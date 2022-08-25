#pragma once
#include "PlayStatus.h"
#include "MediaPlayer.h"
#include <mutex>


//播放器父类
class VLCPlayer
{
public:
	VLCPlayer();

	virtual ~VLCPlayer();

	bool virtual IsPlaying();

	PLAYSTATUS virtual Status();

	bool virtual Rewind(long second);

	bool virtual FastForward(long second);

	void virtual StartOrStop();

	long virtual GetTotalTime();

	long virtual GetNowPlayTime();

	void virtual SetPlayPos(long seekTime);

	void virtual Release();

	void virtual SetRate(float rate);

	void virtual CutPlay();

protected:
	//播放器实例
	libvlc_media_player_t * vlcPlayer;
	//播放器实例
	libvlc_instance_t* vlcInstacnce;

	std::mutex _lock;

	//视频总时长
   long videoTotalMs;

};

