#include "yurchenko.h"

#ifdef _WIN32
void SimulateMousePress(UINT Msg, WPARAM wParam)
{
	POINT pos_cursor;
	GetCursorPos(&pos_cursor);
	HWND window = WindowFromPoint(pos_cursor);
	SendMessage(window, Msg, wParam, MAKELPARAM(pos_cursor.x, pos_cursor.y));
}
#endif

namespace yurchenko
{
	//! Simulates key down event
	/*!
		\param key an integer argument
	*/
	void KeyDown(int key)
	{
		#ifdef __linux__
		Display *display = XOpenDisplay(NULL);
		unsigned char keycode = XKeysymToKeycode(display, key);
		XTestFakeKeyEvent(display, keycode, true, 0)
		XFlush(display);
		XCloseDisplay(display);
		#elif defined(_WIN32)
		INPUT input;
		input.type = 1;
		input.ki.wVk = 0;
		input.ki.wScan = MapVirtualKeyW(key, 0);
		input.ki.dwFlags = 0 | KEYEVENTF_SCANCODE;
		SendInput(1, &input, sizeof(input));
		#endif
	}

	//! Simulates key up event
	/*!
		\param key an integer argument
	*/
	void KeyUp(int key)
	{
		#ifdef __linux__
		Display *display = XOpenDisplay(NULL);
		unsigned char keycode = XKeysymToKeycode(display, key);
		XTestFakeKeyEvent(display, keycode, false, 0)
		XFlush(display);
		XCloseDisplay(display);
		#elif defined(_WIN32)
		INPUT input;
		input.type = 1;
		input.ki.wVk = 0;
		input.ki.wScan = MapVirtualKeyW(key, 0);
		input.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;
		SendInput(1, &input, sizeof(input));
		#endif
	}

	//! Get's mouse position
	/*!
		\param x an integer pointer argument
		\param y an integer pointer argument
	*/
	void GetMousePosition(int *x, int *y)
	{
		#ifdef __linux__
		Display *display = XOpenDisplay(NULL);
		int screen = DefaultScreen(display);
		int win_x, win_y, root_x, root_y = 0;
		Window child_win, root_win;
		XQueryPointer(display, XRootWindow(display, screen), &child_win, &root_win, &root_x, &root_y, &win_x, &win_y, 0);
		*x = root_x;
    	*y = root_y;
		#elif defined(_WIN32)
		POINT point;
		GetCursorPos(&point);
		*x = point.x;
		*y = point.y;
		#endif
	}

	//! Checks if key pressed
	/*!
		\param key an integer argument
	*/
	bool IsKeyPressed(int key)
	{
		#ifdef __linux__
		Display *dpy = XOpenDisplay(NULL);
		char keys_return[32];
		XQueryKeymap(dpy, keys_return);
		KeyCode kc2 = XKeysymToKeycode(dpy, key);
		bool isPressed = !!(keys_return[kc2 >> 3] & (1 << (kc2 & 7)));
		XCloseDisplay(dpy);
		return isPressed;
		#elif defined(_WIN32)
		SHORT pressed = GetAsyncKeyState(key);
		return (1 << 15) & pressed;
		#endif
	}

	//! Moves mouse
	/*!
		\param x an integer argument
		\param y an integer argument
		\param relative an boolean
	*/
	void MouseMove(int x, int y, bool relative)
	{
		#ifdef __linux__
		Display *display = XOpenDisplay(NULL);
		XTestFakeMotionEvent(display, 0, x, y, 0);
		XFlush(display);
		XCloseDisplay(display);
		#elif defined(_WIN32)
		INPUT input;
		input.type = INPUT_MOUSE;
		input.mi.dx = x;
		input.mi.dy = y;
		input.mi.mouseData = 0;
		input.mi.dwFlags = relative ? MOUSEEVENTF_MOVE : (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE);
		SendInput(1, &input, sizeof(input));
		#endif
	}

	//! Simulates mouse wheel event
	/*!
		\param amount an integer argument
	*/
	void MouseWheel(int amount)
	{
		#ifdef __linux__
		#elif defined(_WIN32)
		INPUT input;
		input.type = INPUT_MOUSE;
		input.mi.mouseData = amount;
		input.mi.dwFlags = MOUSEEVENTF_WHEEL;
		SendInput(1, &input, sizeof(input));
		#endif
	}

	//! Simulates left mouse down event
	void LeftMouseDown()
	{
		#ifdef __linux__
		Display *display = XOpenDisplay(NULL);
		XTestFakeButtonEvent(display, 1, true, 0);
		XFlush(display);
		XCloseDisplay(display);
		#elif defined(_WIN32)
		SimulateMousePress(WM_LBUTTONDOWN, MK_LBUTTON);
		#endif
	}

	//! Simulates left mouse up event
	void LeftMouseUp()
	{
		#ifdef __linux__
		Display *display = XOpenDisplay(NULL);
		XTestFakeButtonEvent(display, 1, false, 0);
		XFlush(display);
		XCloseDisplay(display);
		#elif defined(_WIN32)
		SimulateMousePress(WM_LBUTTONUP, 0);
		#endif
	}

	//! Simulates right mouse down event
	void RightMouseDown()
	{
		#ifdef __linux__
		Display *display = XOpenDisplay(NULL);
		XTestFakeButtonEvent(display, 3, true, 0);
		XFlush(display);
		XCloseDisplay(display);
		#elif defined(_WIN32)
		SimulateMousePress(WM_RBUTTONDOWN, MK_RBUTTON);
		#endif
	}

	//! Simulates left mouse up event
	void RightMouseUp()
	{
		#ifdef __linux__
		Display *display = XOpenDisplay(NULL);
		XTestFakeButtonEvent(display, 3, false, 0);
		XFlush(display);
		XCloseDisplay(display);
		#elif defined(_WIN32)
		SimulateMousePress(WM_RBUTTONUP, 0);
		#endif
	}
}