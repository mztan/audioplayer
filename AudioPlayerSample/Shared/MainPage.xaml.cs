using System;
using Windows.UI.Popups;
using Windows.UI.Xaml;
using Em.Media.Playback;

namespace AudioPlayerSample
{
    public sealed partial class MainPage
    {
        private AudioPlayer _audioPlayer;

        public MainPage()
        {
            InitializeComponent();
        }

        private void Alarm_Click(object sender, RoutedEventArgs e)
        {
            PlaySound(new Uri("ms-appx:///Assets/Alarm10.wav"));
        }

        private void Notify_Click(object sender, RoutedEventArgs e)
        {
            PlaySound(new Uri("ms-appx:///Assets/Calendar.wav"));
        }

        private void Ring_Click(object sender, RoutedEventArgs e)
        {
            PlaySound(new Uri("ms-appx:///Assets/Ring02.wav"));
        }

        private async void PlaySound(Uri soundUri)
        {
            Exception exception = null;

            try
            {
                if (_audioPlayer == null)
                    _audioPlayer = new AudioPlayer();

                _audioPlayer.PlaySound(soundUri);
            }
            catch (Exception ex)
            {
                exception = ex;
            }

            if (exception != null)
            {
                var dialog = new MessageDialog(exception.ToString(), "Exception Caught!");
                try
                {
                    await dialog.ShowAsync();
                }
                catch (UnauthorizedAccessException)
                {
                }
            }
        }
    }
}
