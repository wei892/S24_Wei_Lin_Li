#include "pch.h"
#include "EmpireWindow.h"
#include "codeGLFW/WindowGLFW.h"

namespace Empire
{
	EmpireWindow::EmpireWindow()
	{
#ifdef EMPIRE_GLFW_WINDOW
		mWindow = std::unique_ptr<WindowImpl>{ new WindowGLFW };
#else
	#definition_EMPIRE_GLFW_is_missing
#endif
	}

	void EmpireWindow::Init()
	{
		if (!mInstance)
			mInstance = new EmpireWindow;
	}

	EmpireWindow* EmpireWindow::GetWindow()
	{
		return mInstance;
	}

	void EmpireWindow::Shutdown()
	{
		if (mInstance)
			delete mInstance;
	}

	void EmpireWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}

	void EmpireWindow::PollEvents()
	{
		mWindow->PollEvents();
	}

	void EmpireWindow::Create(int width, int height)
	{
		mWindow->Create(width, height);
	}

	int EmpireWindow::GetWidth() const
	{
		return mWindow->GetWidth();
	}

	int EmpireWindow::GetHeight() const
	{
		return mWindow->GetHeight();;
	}
}