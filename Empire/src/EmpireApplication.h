#pragma once

#include "pch.h"
#include "Ultility.h"
#include "EmpireEvents.h"

constexpr int EMPIRE_FRAME_RATE{ 60 };

namespace Empire
{
	class EMPIRE_API EmpireApplication
	{
	public:

		virtual void Initialize();
		virtual void OnUpdate();
		virtual void Shutdown();

		void Run();	

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);


	private:
		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{ 1000 } / EMPIRE_FRAME_RATE };
	};

}