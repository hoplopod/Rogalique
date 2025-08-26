#pragma once

#include <string>

namespace Engine {

	enum class LogLevel {
		INFO,
		WARNING,
		ERROR
	};

	class LogSink {
	public:
		virtual void log(LogLevel level, const std::string& message) = 0;
		virtual ~LogSink() = default;
	};

}
