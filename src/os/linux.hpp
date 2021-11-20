#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XTest.h>
#include <X11/keysym.h>

namespace yurchenko
{
	namespace linux
	{
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
}