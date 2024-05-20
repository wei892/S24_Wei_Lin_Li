#pragma once
#include "pch.h"
#include "WindowImpl.h"
#include "Ultility.h"

namespace Empire {
	class EMPIRE_API EmpireWindow {
	public:
		static void Init();
		static EmpireWindow* GetWindow();
		static void Shutdown();
		
		void SwapBuffers();
		void PollEvents();
		void Create(int width, int height);
		int GetWidth() const;
		int GetHeight() const;
	private:
		inline static EmpireWindow* mInstance{ nullptr };

		std::unique_ptr<WindowImpl> mWindow{nullptr};

		EmpireWindow();
	};
}