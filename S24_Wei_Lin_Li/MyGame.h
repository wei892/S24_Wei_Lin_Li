#pragma once

#include <vector>
#include "Empire.h"
#include <iostream>

class MyGame : public Empire::EmpireApplication
{
public:
	MyGame();

	void OnUpdate();
	void RenderLifes();
	void OnKeyPressed(const Empire::KeyPressed& e);
	void OnKeyReleased(const Empire::KeyReleased& e);
	void UpdateBearPosition();


private:
	//bear details
	int bearDir = 0;
	Empire::Unit bear{ "..\\Assets\\bearFacingLeft.png", bearXPos , bearYPos};
	//leftBear = 0
	Empire::Image bearLeft{ "..\\Assets\\bearFacingLeft.png" };
	//rightBear = 1
	Empire::Image bearRight{ "..\\Assets\\bearFacingRight.png" };
	enum class State{stop, move} mState;
	int bearXPos = 450;
	int bearYPos = 50;
	int bearSpeed = 20;

	//other details
	Empire::Image background{ "..\\Assets\\background.png"};
	Empire::Image mHeart{ "..\\Assets\\heart.png" };
	Empire::Image startButton{ "..\\Assets\\startButton.png" };
	std::vector <Empire::Image> threeLives;

	int Score{ 0 };
	int lifeCount = 3;
	int leftBoundary = 170;
	int rightBoundary = 970;
	int itemDropLeftBound = 200;
	int itemDroprightBound = 800;

	//itemDropped details
	int itemNum = 0;
	int itemXPos = -50;
	int itemYPos = -100;
	bool touchedORFallen = false;
	Empire::Unit itemDropped{ "..\\Assets\\startButton.png" , itemXPos , itemYPos };
	bool isBee = false;

	bool playingGame = false;
};