#include "VLCPlayer.h"

using namespace std;

VLCPlayer::VLCPlayer()
{
	this->vlcInstacnce = MediaPlayer::Create_Media_Instacne();
}

VLCPlayer::~VLCPlayer()
{
	Release();
}

bool VLCPlayer::IsPlaying()
{
	if (vlcPlayer != NULL)
	{
		lock_guard<mutex> lock(_lock);
		return MediaPlayer::MediaPlayer_IsPlaying(vlcPlayer);
	}

	return false;
}

//获取播放的状态
PLAYSTATUS VLCPlayer::Status()
{
	int status;

	{
		lock_guard<mutex> lock(_lock);
		status = MediaPlayer::GetStatus(vlcPlayer);
	}

	PLAYSTATUS res = PLAYSTATUS::CLOSE;
	switch (status)
	{
	case 0:
		res = PLAYSTATUS::CLOSE;
		break;
	case 1:
		res = PLAYSTATUS::OPENING;
		break;
	case 3:
		res = PLAYSTATUS::PALYING;
		break;
	case 4:
		res = PLAYSTATUS::PAUSED;
		break;
	case 5:
		res = PLAYSTATUS::STOPPING;
		break;
	case 6:
		res = PLAYSTATUS::ENDED;
		break;
	case 7:
		res = PLAYSTATUS::ERR;
		break;
	}
	return res;

}

bool VLCPlayer::Rewind(long second)
{
	if (this->IsPlaying())
	{
		long millionSecond = second * 1000;

		if (GetNowPlayTime() - millionSecond <= 0)
		{
			millionSecond = 0;
		}

		if (MediaPlayer::MediaPlayer_Back(vlcPlayer, millionSecond))
		{
			return true;
		}
		return false;
	}
	return true;
}

bool VLCPlayer::FastForward(long second)
{
	if (this->IsPlaying())
	{
		long millionSecond = (long)second * 1000;

		if (GetNowPlayTime() + millionSecond >= videoTotalMs)
		{
			millionSecond = videoTotalMs;
		}

		if (MediaPlayer::MediaPlayer_Forward(vlcPlayer, millionSecond))
		{
			return true;
		}

		return false;
	}
	return true;
}

void VLCPlayer::StartOrStop()
{
	MediaPlayer::MediaPlayer_Pause(vlcPlayer);
}

long VLCPlayer::GetTotalTime()
{
	return this->videoTotalMs;
}

long VLCPlayer::GetNowPlayTime()
{
	lock_guard<mutex> lock(_lock);
	return MediaPlayer::GetNowPlayTime(vlcPlayer);
}

void VLCPlayer::SetPlayPos(long seekTime)
{
	MediaPlayer::Seek(vlcPlayer, seekTime);
}

void VLCPlayer::Release()
{
	MediaPlayer::Release_MediaPlayer(vlcPlayer);
	MediaPlayer::Release_Media_Instance(vlcInstacnce);
}

void VLCPlayer::SetRate(float rate)
{
	MediaPlayer::SetRate(vlcPlayer, rate);
}

void VLCPlayer::CutPlay()
{
	if (IsPlaying())
	{
		MediaPlayer::MediaPlayer_Stop(vlcPlayer);
	}
}
