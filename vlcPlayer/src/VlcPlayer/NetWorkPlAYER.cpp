#include "NetWorkPlAYER.h"


void NetWorkPlayer::Start(std::string url, void * handle)
{
	this->videoUrl = url;
	this->vlcPlayer = MediaPlayer::Create_MediaPlayer(vlcInstacnce, handle);
	MediaPlayer::NetWork_Media_Play(vlcInstacnce, vlcPlayer, url);

	this->videoTotalMs = MediaPlayer::GetTotalTime(vlcPlayer);
}

void NetWorkPlayer::Start(std::string url)
{
	MediaPlayer::NetWork_Media_Play(vlcInstacnce, vlcPlayer, url);
	this->videoTotalMs = MediaPlayer::GetTotalTime(vlcPlayer);
}

void NetWorkPlayer::StartPlayer()
{
	MediaPlayer::NetWork_Media_Play(vlcInstacnce, vlcPlayer, this->videoUrl);
	videoTotalMs = MediaPlayer::GetTotalTime(vlcPlayer);
}
