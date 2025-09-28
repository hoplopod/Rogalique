@echo off
:: Batch file to build the Game.sln solution

:: Step 1: Define paths and configuration
set SOLUTION_PATH=Game.sln
set MSBUILD_PATH="C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\MSBuild.exe"
set CONFIGURATIOn=Debug
set PLATFORM=x64

:: Step 2: Cheack if MSbuild exists
if not exist %MSBUILD_PATH% (
	echo MSBuild not found at %MSBUILD_PATH%. Please check your installation.
	pause
	exit /b 1
)

:: Step 3: Build the solution
echo Building solution: %SOLUTION_PATH%
echo Configuration: %CONFIGURATION%

%MSBUILD_PATH% %SOLUTION_PATH% ^
	/p:Configuration=%CONFIGURATION% ^
	/p:Platform=%PLATFORM% ^
	/t:Engine;Roguelike

:: Step 4: Check build result
if %ERRORLEVEL% neq 0 (
	echo Build failed
	pause
	exit /b %ERRORLEVEL%
)

:: Step 5: Copy required DLL file
if exist "%CD%\SFML\SFML-2.5.1\bin\" (
	mkdir "%CD%\%PLATFORM%\%CONFIGURATION%" >nul
	copy "%CD%\SFML\SFML-2.5.1\bin\openal32.dll" "%CD%\%PLATFORM%\%CONFIGURATION%" >nul
	echo Copied DLL files to output directory.
)

:: Step 6: Copy resource files
set "RES_SRC1=%CD%\Roguelike\Resources"
set "RES_DST=%CD%\%PLATFORM%\%CONFIGURATION%\Resources"

if exist "%RES_SRC1%\" (
    mkdir "%RES_DST%" >nul
    xcopy /E /I /Y "%RES_SRC1%\*" "%RES_DST%\" >nul
    echo Copied resource files from Roguelike\Resources to output directory.

)
 else (
    echo WARNING: Resources folder not found.
    echo   Expected: "%RES_SRC1%"
)


:: Step 7: Search and launch executable
set "TARGET=Roguelike.exe"
set "EXE_PATH=%CD%\%PLATFORM%\%CONFIGURATION%\%TARGET%"
if not exist "%EXE_PATH%" (
    set "EXE_PATH=%CD%\Roguelike\%PLATFORM%\%CONFIGURATION%\%TARGET%"
)
if not exist "%EXE_PATH%" (
    for /f "delims=" %%I in ('dir /s /b "%CD%\%TARGET%" 2^>nul') do set "EXE_PATH=%%I"
)
if exist "%EXE_PATH%" (
    echo Launching "%EXE_PATH%"
  
    start "" /D "%CD%\%PLATFORM%\%CONFIGURATION%" "%EXE_PATH%"
) else (
    echo ERROR: Executable "%TARGET%" not found. Fix TARGET/paths in this script.
    pause
    exit /b 1
)

echo Build completed successfully.