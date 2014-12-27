#pragma once

#include "XAudio2SoundPlayer.h"

namespace Em { 
    namespace Media { 
        namespace Playback {
            public ref class AudioPlayer sealed
            {
            public:
                AudioPlayer();
                virtual ~AudioPlayer();
                bool PlaySound(Windows::Foundation::Uri^ uri);

            private:
                static const uint32 SOUND_SAMPLE_RATE = 22050;

                size_t LoadSound(Platform::String^ path);
                void OnSuspending(Platform::Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ args);
                void OnResuming(Platform::Object^ sender, Platform::Object^ args);

                std::map<Platform::String^, size_t>  m_sounds;
                XAudio2SoundPlayer* m_soundPlayer;
            };
        }
    }
}