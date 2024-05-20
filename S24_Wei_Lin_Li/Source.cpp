#include "Empire.h"
#include <iostream>

class MyGame : public Empire::EmpireApplication
{
	virtual void Initialize() override
	{
		//my_window.Create(1000, 800);
	}
	virtual void OnUpdate() override
	{
		std::cout << "Window Width " << Empire::EmpireWindow::GetWindow()->GetWidth() << std::endl;
	}
private:

};

START_GAME(MyGame)