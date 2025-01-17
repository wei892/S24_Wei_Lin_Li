#include "pch.h"
#include "EmpireEvents.h"

namespace Empire
{
	KeyPressed::KeyPressed(int kCode):mKeyCode(kCode)
	{
	}

	int KeyPressed::GetKeyCode() const
	{
		return mKeyCode;
	}

	KeyReleased::KeyReleased(int kCode):mKeyCode(kCode)
	{
	}
	int KeyReleased::GetKeyCode() const
	{
		return mKeyCode;
	}
}