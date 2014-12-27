audioplayer
===========

Simple WinRT component for playing sound effects using XAudio2. Supports Windows 8.1+ and Windows Phone 8.1+.

#### Features
* Extremely easy to use
* Supports playing multiple sounds at the same time (unlike MediaElement)

#### Usage
    Em.Media.Playback.AudioPlayer player = new Em.Media.Playback.AudioPlayer();
    player.PlaySound(new Uri("ms-appx:///Assets/your-sound.wav"));

Comments and pull requests are more than welcome.
