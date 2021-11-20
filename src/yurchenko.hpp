#ifdef _WIN32
	#include <windows.h>
	#include <WinUser.h>
#elif defined(__linux__)
	#include <X11/Xlib.h>
	#include <X11/Xutil.h>
	#include <X11/extensions/XTest.h>
	#include <X11/keysym.h>
#elif defined(__APPLE__)
	#include <ApplicationServices/ApplicationServices.h>
#endif

namespace yurchenko
{
	#include "const/keys.hpp"

	void KeyDown(int key);
	void KeyUp(int key);

	void GetMousePosition(int *x, int *y);
	bool IsKeyPressed(int key);

	void MouseMove(int x, int y);
	void RelativeMouseMove(int x, int y);
	void MouseWheel(int amount);

	void LeftMouseDown();
	void LeftMouseUp();

	void RightMouseDown();
	void RightMouseUp();
}