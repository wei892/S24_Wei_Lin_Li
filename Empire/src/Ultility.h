#pragma once

#define START_GAME(className) \
int main()\
{\
	className _game;\
	_game.Run();\
	return 0;\
}

#ifdef EMPIRE_MS_COMPILER
	#ifdef EMPIRE_LIB
		#define EMPIRE_API __declspec(dllexport)
	#else
		#define EMPIRE_API __declspec(dllimport)
	#endif
#else
	#define EMPIRE_API
#endif

#if EMPIRE_DEBUG == 2
	#define EMPIRE_ERROR(x) std::cout << x << std::endl;
	#define EMPIRE_LOG(x) std::cout << x << std::endl;
#elif EMPIRE_DEBUG == 1
	#define EMPIRE_ERROR(x) std::cout << x << std::endl;
	#define EMPIRE_LOG(x);
#else
	#define EMPIRE_ERROR(x);
	#define EMPIRE_LOG(x);
#endif

