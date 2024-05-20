#include "pch.h"

#include "EmpireApplication.h"
#include "EmpireWindow.h"

namespace Empire 
{
	void EmpireApplication::Initialize()
	{

	}
	void EmpireApplication::OnUpdate()
	{

	}
	void EmpireApplication::Shutdown()
	{

	}
	void EmpireApplication::Run()
	{
		EmpireWindow::Init();
		EmpireWindow::GetWindow()->Create(1000, 800);
		Initialize();

		while (true)
		{
			OnUpdate();

			EmpireWindow::GetWindow()->SwapBuffers();
			EmpireWindow::GetWindow()->PollEvents();
		}
		Shutdown();
		EmpireWindow::Shutdown();
	}
}