#pragma once
#include "VLCPlayer.h"
#include <iostream>

//���粥����
class NetWorkPlayer :
	public VLCPlayer
{
public:
	void Start(std::string url, void * handle);

	void Start(std::string url);

	void StartPlayer();

private:
	std::string videoUrl;
};

