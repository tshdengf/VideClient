#include "MediaPlayer.h"
#include <qdir.h>
#include <qstring.h>
#include <thread>

using namespace std;

string MediaPlayer::pluginPath = "";

string MediaPlayer::pluginArg = "";

long MediaPlayer::totalTime = 0;

//创建Insance
libvlc_instance_t* MediaPlayer::Create_Media_Instacne()
{
	libvlc_instance_t *instance = NULL;

	QDir cur_path(QDir::currentPath());
	cur_path.cdUp();
	pluginPath = (cur_path.absolutePath() + "//bin//plugins").toStdString();
	pluginArg = "--plugin-path=" + pluginPath;

	const char *arguments[] = { "-I", "dummy", "--ignore-config", "--video-title", pluginArg.c_str() };

	instance = libvlc_new(sizeof(arguments)/sizeof(arguments[0]), arguments);

	return instance;
}
//释放
void MediaPlayer::Release_Media_Instance(libvlc_instance_t * _instance)
{
	if (_instance != NULL)
	{
		libvlc_release(_instance);
		_instance = NULL;
	}
}

//创建媒体播放器
libvlc_media_player_t * MediaPlayer::Create_MediaPlayer(libvlc_instance_t * libvlc_instance, void* handle)
{
	libvlc_media_player_t * media_player = NULL;

	if (libvlc_instance == NULL || handle == NULL) return NULL;

	media_player = libvlc_media_player_new(libvlc_instance);

	libvlc_media_player_set_hwnd(media_player, handle);

	return media_player;
}

//释放媒体播放器
void MediaPlayer::Release_MediaPlayer(libvlc_media_player_t * media_player)
{
	if (media_player != NULL)
	{
		if (libvlc_media_player_is_playing(media_player))
		{
			libvlc_media_player_stop(media_player);
		}
		libvlc_media_player_release(media_player);
		media_player = NULL;
	}
}

//播放指定URL视频
bool MediaPlayer::NetWork_Media_Play(libvlc_instance_t * libvlc_instance, libvlc_media_player_t * libvlc_media_player, string url)
{
	libvlc_media_t * libvlc_media = NULL;

	if (url.empty() || libvlc_instance == NULL || libvlc_media_player == NULL) return false;

	libvlc_media = libvlc_media_new_location(libvlc_instance, url.data());
	if (libvlc_media == NULL) return false;

	//将Media绑定到播放器上
	libvlc_media_player_set_media(libvlc_media_player, libvlc_media);

	//释放libvlc_media资源
	libvlc_media_release(libvlc_media);
	libvlc_media = NULL;

	totalTime = -1;
	libvlc_event_manager_t *vlc_evt_man = libvlc_media_player_event_manager(libvlc_media_player);

	libvlc_event_attach(vlc_evt_man, libvlc_MediaPlayerLengthChanged, Media_LengthChange_CallBack, NULL);

	//播放
	if (0 != libvlc_media_player_play(libvlc_media_player))
	{
		return false;
	}

	return true;

}

//停止
bool MediaPlayer::MediaPlayer_Pause(libvlc_media_player_t * libvlc_media_player)
{
	if (libvlc_media_player == NULL)
	{
		return false;
	}

	if (libvlc_media_player_can_pause(libvlc_media_player))
	{
		libvlc_media_player_pause(libvlc_media_player);

		return true;
	}
	else
	{
		return false;
	}
}
//暂停
bool MediaPlayer::MediaPlayer_Stop(libvlc_media_player_t * libvlc_media_player)
{
	if (libvlc_media_player == NULL)
	{
		return false;
	}

	libvlc_media_player_stop(libvlc_media_player);

	return true;
}

//快进
bool MediaPlayer::MediaPlayer_Forward(libvlc_media_player_t * libvlc_media_player, long millionSecond)
{
	long time = 0;

	if (libvlc_media_player == NULL)
	{
		return false;
	}

	time = libvlc_media_player_get_time(libvlc_media_player);
	if (time == -1)
	{
		return false;
	}

	Seek(libvlc_media_player, time + millionSecond);
	return true;
}

//后退
bool MediaPlayer::MediaPlayer_Back(libvlc_media_player_t * libvlc_media_player, long millionSecond)
{
	long time = 0;

	if (libvlc_media_player == NULL)
	{
		return false;
	}

	time = libvlc_media_player_get_time(libvlc_media_player);
	if (time == -1)
	{
		return false;
	}

	Seek(libvlc_media_player, time - millionSecond);
	return true;
}

bool MediaPlayer::MediaPlayer_IsPlaying(libvlc_media_player_t * libvlc_media_player)
{
	if (libvlc_media_player == NULL)
	{
		return false;
	}
	return libvlc_media_player_is_playing(libvlc_media_player);
}

long MediaPlayer::GetTotalTime(libvlc_media_player_t * libvlc_media_player)
{
	if (libvlc_media_player == NULL)
	{
		return 0;
	}

	libvlc_media_t* media = NULL;
	media = libvlc_media_player_get_media(libvlc_media_player);
	if (media == NULL)
	{
		return 0;
	}
	int res = libvlc_media_parse_with_options(media, libvlc_media_parse_network, -1);

	while (totalTime == -1)
	{
		this_thread::sleep_for(chrono::milliseconds(100));
		continue;
	}
	return totalTime;
	//return libvlc_media_get_duration(media);
}

long MediaPlayer::GetNowPlayTime(libvlc_media_player_t * libvlc_media_player)
{
	if (libvlc_media_player == NULL)
	{
		return 0;
	}

	return libvlc_media_player_get_time(libvlc_media_player);
}

void MediaPlayer::SetRate(libvlc_media_player_t * libvlc_media_player, float rate)
{
	if (libvlc_media_player == NULL)
	{
		return;
	}

	if (MediaPlayer_IsPlaying(libvlc_media_player))
	{
		libvlc_media_player_set_rate(libvlc_media_player, rate);
	}
}

void MediaPlayer::Seek(libvlc_media_player_t * libvlc_media_player, long seekTime)
{
	if (libvlc_media_player == NULL)
	{
		return;
	}

	if (libvlc_media_player_is_seekable(libvlc_media_player))
	{
		libvlc_media_player_set_time(libvlc_media_player, seekTime);
	}
}

int MediaPlayer::GetStatus(libvlc_media_player_t * libvlc_media_player)
{
	if (libvlc_media_player != NULL)
	{
		return (int)libvlc_media_player_get_state(libvlc_media_player);
	}

	return 0;
}

void MediaPlayer::Media_LengthChange_CallBack(const libvlc_event_t * p_event, void * p_data)
{
	auto timeT = p_event->u.media_duration_changed.new_duration;

	if (timeT == -1)
	{
		totalTime = 0;
		return;
	}
	totalTime = timeT;
}




