#pragma once

//#include "pch.h"
#include "Ultility.h"


namespace Empire
{
	class EMPIRE_API KeyPressed
	{
	public:
		KeyPressed(int kCode);
		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class EMPIRE_API KeyReleased
	{
	public:
		KeyReleased(int kCode);
		int GetKeyCode() const;
	private:
		int mKeyCode;
	};
}
