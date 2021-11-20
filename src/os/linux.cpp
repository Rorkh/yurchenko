#ifdef __linux__
	#include "../yurchenko.hpp"
	#include <cmath>

	namespace yurchenko 
	{
		namespace linux
		{
			void KeyDown(int key)
			{
				Display *display = XOpenDisplay(NULL);
				unsigned char keycode = XKeysymToKeycode(display, key);
				XTestFakeKeyEvent(display, keycode, true, 0);
				XFlush(display);
				XCloseDisplay(display);
			}

			void KeyUp(int key)
			{
				Display *display = XOpenDisplay(NULL);
				unsigned char keycode = XKeysymToKeycode(display, key);
				XTestFakeKeyEvent(display, keycode, false, 0);
				XFlush(display);
				XCloseDisplay(display);
			}

			void GetMousePosition(int *x, int *y)
			{
				Display *display = XOpenDisplay(NULL);
				int screen = DefaultScreen(display);
				int win_x, win_y, root_x, root_y = 0;
				Window child_win, root_win;
				XQueryPointer(display, XRootWindow(display, screen), &child_win, &root_win, &root_x, &root_y, &win_x, &win_y, 0);
				*x = root_x;
				*y = root_y;
			}

			bool IsKeyPressed(int key)
			{
				Display *dpy = XOpenDisplay(NULL);
				char keys_return[32];
				XQueryKeymap(dpy, keys_return);
				KeyCode kc2 = XKeysymToKeycode(dpy, key);
				bool isPressed = !!(keys_return[kc2 >> 3] & (1 << (kc2 & 7)));
				XCloseDisplay(dpy);
				return isPressed;
			}

			void MouseMove(int x, int y)
			{
				Display *display = XOpenDisplay(NULL);
				XTestFakeMotionEvent(display, 0, x, y, 0);
				XFlush(display);
				XCloseDisplay(display);
			}

			void RelativeMouseMove(int x, int y)
			{
				Display *display = XOpenDisplay(NULL);
				XTestFakeRelativeMotionEvent(display, x, y, 0);
				XFlush(display);
				XCloseDisplay(display);
			}

			void MouseWheel(int amount)
			{
				Display *display = XOpenDisplay(NULL);
				if (amount < 0)
				{
					for(int i = 0; i < abs(amount) && i < 5; i++) {
						XTestFakeButtonEvent(display, 5, true, 0);
						XTestFakeButtonEvent(display, 5, false, 0);
					}
				}
				else if (amount > 0)
				{
					for(int i = 0; i < abs(amount) && i < 5; i++) {
						XTestFakeButtonEvent(display, 4, true, 0);
						XTestFakeButtonEvent(display, 4, false, 0);
					}
				}
				XFlush(display);
				XCloseDisplay(display);
			}

			void LeftMouseDown()
			{
				Display *display = XOpenDisplay(NULL);
				XTestFakeButtonEvent(display, 1, true, 0);
				XFlush(display);
				XCloseDisplay(display);
			}

			void LeftMouseUp()
			{
				Display *display = XOpenDisplay(NULL);
				XTestFakeButtonEvent(display, 1, false, 0);
				XFlush(display);
				XCloseDisplay(display);
			}

			void RightMouseDown()
			{
				Display *display = XOpenDisplay(NULL);
				XTestFakeButtonEvent(display, 3, true, 0);
				XFlush(display);
				XCloseDisplay(display);
			}

			void RightMouseUp()
			{
				Display *display = XOpenDisplay(NULL);
				XTestFakeButtonEvent(display, 3, false, 0);
				XFlush(display);
				XCloseDisplay(display);
			}
		}
	}
#endif