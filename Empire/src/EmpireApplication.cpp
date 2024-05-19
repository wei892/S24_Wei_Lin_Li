#include "pch.h"

#include "EmpireApplication.h"

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
		Initialize();

		while (true)
		{
			OnUpdate();
		}
		Shutdown();
	}
}