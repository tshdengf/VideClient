#pragma once
#include "PlayStatus.h"
#include "MediaPlayer.h"
#include <mutex>


//����������
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
	//������ʵ��
	libvlc_media_player_t * vlcPlayer;
	//������ʵ��
	libvlc_instance_t* vlcInstacnce;

	std::mutex _lock;

	//��Ƶ��ʱ��
   long videoTotalMs;

};

