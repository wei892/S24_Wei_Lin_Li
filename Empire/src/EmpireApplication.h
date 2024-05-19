#pragma once

#include "Ultility.h"

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
	

	};

}