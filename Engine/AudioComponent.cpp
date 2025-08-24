#include "pch.h"
#include "AudioComponent.h"

Engine::AudioComponent::AudioComponent(GameObject* gameObject)
	: Component(gameObject)
{
	sound = new sf::Sound();
}

Engine::AudioComponent::~AudioComponent()
{
	sound->stop();
	delete sound;
}

void Engine::AudioComponent::Update(float deltaTime)
{
}

void Engine::AudioComponent::Render()
{
}

void Engine::AudioComponent::SetAudio(const sf::SoundBuffer& audio)
{
	sound->setBuffer(audio);
}

void Engine::AudioComponent::SetLoop(bool loop)
{
	sound->setLoop(loop);
}

void Engine::AudioComponent::SetVolume(float volume)
{
	sound->setVolume(volume);
}

void Engine::AudioComponent::Play()
{
	if (sound->getStatus() != sf::SoundSource::Playing)
	{
		sound->play();
	}
}

void Engine::AudioComponent::Stop()
{
	sound->stop();
}

void Engine::AudioComponent::Pause()
{
	sound->pause();
}

void Engine::AudioComponent::Resume()
{
	if (sound->getStatus() != sf::SoundSource::Playing)
	{
		sound->play();
	}
}
