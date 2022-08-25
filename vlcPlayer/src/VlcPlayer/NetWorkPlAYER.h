#pragma once
#include "VLCPlayer.h"
#include <iostream>

//ÍøÂç²¥·ÅÆ÷
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

