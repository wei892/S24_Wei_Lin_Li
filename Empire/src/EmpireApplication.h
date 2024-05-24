#pragma once

#include "pch.h"
#include "Ultility.h"
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
	private:
		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::duration<int, std::chrono::milliseconds::period> mFrameDuration{ 1000 / EMPIRE_FRAME_RATE };
	};

}