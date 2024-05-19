#include "Empire.h"
#include <iostream>

class MyGame : public Empire::EmpireApplication
{
	virtual void OnUpdate() override
	{
		std::cout << "Engine is running" << std::endl;
	}

};

START_GAME(MyGame)