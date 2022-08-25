#pragma once

#include <string>
#ifdef _WIN32
#include <basetsd.h>
typedef SSIZE_T ssize_t;
#endif
extern "C"
{
#include "vlc/libvlc.h"
#include "vlc/libvlc_media.h"
#include "vlc/libvlc_media_player.h"
#include "vlc/libvlc_events.h"
}


//vlc ²¥·ÅÆ÷·â×°
class MediaPlayer
{
public:
	static libvlc_instance_t *Create_Media_Instacne();

	static void Release_Media_Instance(libvlc_instance_t* _instance);

	static libvlc_media_player_t*Create_MediaPlayer(libvlc_instance_t *libvlc_instance, void* handle);

	static void Release_MediaPlayer(libvlc_media_player_t* media_player);

	static bool NetWork_Media_Play(libvlc_instance_t* libvlc_instance, libvlc_media_player_t* libvlc_media_player, std::string url);

	static bool MediaPlayer_Pause(libvlc_media_player_t* libvlc_media_player);


	static bool MediaPlayer_Stop(libvlc_media_player_t* libvlc_media_player);

	static bool MediaPlayer_Forward(libvlc_media_player_t* libvlc_media_player, long millionSecond);

	static bool MediaPlayer_Back(libvlc_media_player_t* libvlc_media_player, long millionSecond);

	static bool MediaPlayer_IsPlaying(libvlc_media_player_t* libvlc_media_player);

	static long GetTotalTime(libvlc_media_player_t* libvlc_media_player);

	static long GetNowPlayTime(libvlc_media_player_t* libvlc_media_player);

	static void SetRate(libvlc_media_player_t* libvlc_media_player, float rate);

	static void Seek(libvlc_media_player_t* libvlc_media_player, long seekTime);

	static int GetStatus(libvlc_media_player_t* libvlc_media_player);

	static void Media_LengthChange_CallBack(const struct libvlc_event_t *p_event, void *p_data);

private:
	static std::string pluginPath;
	static std::string pluginArg;

	static long totalTime;
};






