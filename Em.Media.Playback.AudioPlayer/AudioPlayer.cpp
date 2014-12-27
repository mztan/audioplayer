#include "pch.h"
#include "AudioPlayer.h"
#include "SoundFileReader.h"

using namespace std;
using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::Foundation;
using namespace Em::Media::Playback;

AudioPlayer::AudioPlayer()
{
    m_soundPlayer = new XAudio2SoundPlayer(SOUND_SAMPLE_RATE);

    CoreApplication::Suspending +=
        ref new EventHandler<SuspendingEventArgs^>(this, &AudioPlayer::OnSuspending);

    CoreApplication::Resuming +=
        ref new EventHandler<Platform::Object^>(this, &AudioPlayer::OnResuming);
}

AudioPlayer::~AudioPlayer()
{
    if (m_soundPlayer != nullptr)
    {
        delete m_soundPlayer;
        m_soundPlayer = nullptr;
    }
}

bool AudioPlayer::PlaySound(Windows::Foundation::Uri^ uri)
{
    if (uri == nullptr)
        throw ref new InvalidArgumentException();

    size_t soundIndex = LoadSound(uri->Path);

    return m_soundPlayer->PlaySound(soundIndex);
}

size_t AudioPlayer::LoadSound(String^ path)
{
    auto& iter = m_sounds.find(path);
    if (iter != m_sounds.end())
    {
        return iter->second;
    }

    SoundFileReader sound(path);
    auto soundIndex = m_soundPlayer->AddSound(sound.GetSoundFormat(), sound.GetSoundData());
    m_sounds[path] = soundIndex;
    return soundIndex;
}

void AudioPlayer::OnSuspending(Platform::Object^ sender, SuspendingEventArgs^ args)
{
    m_soundPlayer->Suspend();
}

void AudioPlayer::OnResuming(Platform::Object^ sender, Platform::Object^ args)
{
    m_soundPlayer->Resume();
}