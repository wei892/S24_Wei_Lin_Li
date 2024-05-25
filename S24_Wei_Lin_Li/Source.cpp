#include "Empire.h"
#include <iostream>
#include "MyGame.h"

START_GAME(MyGame)

/*
class MyGame : public Empire::EmpireApplication
{

	virtual void Initialize() override
	{

	}
	virtual void OnUpdate() override
	{
		Empire::Unit background{ "..\\Assets\\background.png", 0, 0 };
		Empire::Renderer::Draw(background);

		Empire::Unit heart1{ "..\\Assets\\heart.png", 700, 700 };
		Empire::Renderer::Draw(heart1);

		Empire::Unit heart2{ "..\\Assets\\heart.png", 800, 700 };
		Empire::Renderer::Draw(heart2);

		Empire::Unit heart3{ "..\\Assets\\heart.png", 900, 700 };
		Empire::Renderer::Draw(heart3);

		//bear x axis = 100
		int bearXPos = 20;
		int bearYPos = 20;
		if (bearXPos >= 20 && bearXPos <= 980)
		{
			bearXPos += 10;
			Empire::Unit bearRight{ "..\\Assets\\bearFacingRight.png", bearXPos, bearYPos };
			Empire::Renderer::Draw(bearRight);
		}
	}
	private:

};
*/