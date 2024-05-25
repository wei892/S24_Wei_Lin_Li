#include "MyGame.h"
#include "Empire.h"
#include <stdlib.h>

MyGame::MyGame()
{
	SetKeyPressedCallback([this](const Empire::KeyPressed& e) { OnKeyPressed(e); });
	SetKeyReleasedCallback([this](const Empire::KeyReleased& e) { OnKeyReleased(e); });
}

void MyGame::OnUpdate()
{
	if (lifeCount == 0) {
		Empire::Renderer::ClearScreen();
		Empire::Image gameOver{ "..\\Assets\\GameOver.png" };
		Empire::Renderer::Draw(gameOver, 0, 0);
	}
	else if (playingGame == false) 
	{
		Empire::Renderer::Draw(background, 0, 0);
		RenderLifes();
		Empire::Renderer::Draw(bear);
		Empire::Renderer::Draw(itemDropped);
	}
	else {
		Empire::Renderer::Draw(background, 0, 0);
		RenderLifes();

		if (itemYPos < 50) {
			touchedORFallen = true;
		}
		else if (Empire::UnitsOverlap(bear, itemDropped) && isBee == true) {
			lifeCount -= 1;
			touchedORFallen = true;
			isBee = false;
		}
		else if (Empire::UnitsOverlap(bear, itemDropped)) {
			touchedORFallen = true;
		}

		if (touchedORFallen) {
			int randomItem = rand() % 3 + 1;
			itemNum = randomItem;

			int randomXPos = rand() % (itemDroprightBound - itemDropLeftBound);
			itemXPos = randomXPos;
			itemYPos = 1000;
			touchedORFallen = false;
		}
		else {
			itemYPos -= 20;
		}

		if (itemNum == 1) {
			itemDropped = { "..\\Assets\\star.png" , itemXPos, itemYPos };
			isBee = false;
		}
		else if (itemNum == 2)
		{
			itemDropped = { "..\\Assets\\flower.png" , itemXPos, itemYPos };
			isBee = false;
		}
		else if (itemNum == 3)
		{
			itemDropped = { "..\\Assets\\bee.png" , itemXPos, itemYPos };
			isBee = true;
		}

		Empire::Renderer::Draw(itemDropped);

		//render bear movements
		UpdateBearPosition();
		if (bearDir == 0) {
			bear = { "..\\Assets\\bearFacingLeft.png", bearXPos, bearYPos };
		}
		else if (bearDir == 1) {
			bear = { "..\\Assets\\bearFacingRight.png", bearXPos, bearYPos };	
		}

		Empire::Renderer::Draw(bear);
	}
}

void MyGame::RenderLifes()
{
	if (lifeCount >= 1)
	{
		Empire::Renderer::Draw(mHeart, 900, 900);
		if (lifeCount >= 2) {
			Empire::Renderer::Draw(mHeart, 800, 900);
			if (lifeCount >= 3) {
				Empire::Renderer::Draw(mHeart, 700, 900);
			}
		}
	}
}

void MyGame::OnKeyPressed(const Empire::KeyPressed& e)
{
	if (e.GetKeyCode() == EMPIRE_KEY_RIGHT)
	{
		bearDir = 1;
		mState = State::move;
	}
	else if (e.GetKeyCode() == EMPIRE_KEY_LEFT)
	{
		bearDir = 0;
		mState = State::move;
	}
	else if (e.GetKeyCode() == EMPIRE_KEY_SPACE) 
	{
		playingGame = true;
	}

}

void MyGame::OnKeyReleased(const Empire::KeyReleased& e)
{
	if (e.GetKeyCode() == EMPIRE_KEY_RIGHT || e.GetKeyCode() == EMPIRE_KEY_LEFT)
	{
		mState = State::stop;
	}
}

void MyGame::UpdateBearPosition()
{
	if(mState != State::move)
		return;

	if (bearDir == 0) {
		bearXPos = std::max(leftBoundary - bearLeft.GetWidth(), bearXPos - bearSpeed);
	}
	else if (bearDir == 1){
		bearXPos = std::min(rightBoundary - bearRight.GetWidth(), bearXPos + bearSpeed);
	}
}
