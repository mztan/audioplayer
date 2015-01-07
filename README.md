audioplayer
===========

Simple WinRT component for playing sound effects using XAudio2. Based on the [MSDN XAudio2 sample](https://code.msdn.microsoft.com/windowsapps/Basic-Audio-Sample-9a5bb0b7) but makes it easier to use. Supports Windows 8.1+ and Windows Phone 8.1+.

#### Features
* Extremely easy to use
* Supports playing multiple sounds at the same time (unlike MediaElement)
* Abstracts away the complexities of DirectX

#### Usage
    Em.Media.Playback.AudioPlayer player = new Em.Media.Playback.AudioPlayer();
    player.PlaySound(new Uri("ms-appx:///Assets/your-sound.wav"));

Comments and pull requests are more than welcome.
