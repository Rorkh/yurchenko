#ifdef _WIN32
	#include "../yurchenko.hpp"

	void SimulateMousePress(UINT Msg, WPARAM wParam)
	{
		POINT pos_cursor;
		GetCursorPos(&pos_cursor);
		HWND window = WindowFromPoint(pos_cursor);
		SendMessage(window, Msg, wParam, MAKELPARAM(pos_cursor.x, pos_cursor.y));
	}

	namespace yurchenko 
	{
		namespace windows
		{
			void KeyDown(int key)
			{
				INPUT input;
				input.type = 1;
				input.ki.wVk = 0;
				input.ki.wScan = MapVirtualKeyW(key, 0);
				input.ki.dwFlags = 0 | KEYEVENTF_SCANCODE;
				SendInput(1, &input, sizeof(input));
			}

			void KeyUp(int key)
			{
				INPUT input;
				input.type = 1;
				input.ki.wVk = 0;
				input.ki.wScan = MapVirtualKeyW(key, 0);
				input.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;
				SendInput(1, &input, sizeof(input));
			}

			void GetMousePosition(int *x, int *y)
			{
				POINT point;
				GetCursorPos(&point);
				*x = point.x;
				*y = point.y;
			}

			bool IsKeyPressed(int key)
			{
				SHORT pressed = GetAsyncKeyState(key);
				return (1 << 15) & pressed;
			}

			void MouseMove(int x, int y)
			{
				INPUT input;
				input.type = INPUT_MOUSE;
				input.mi.dx = x;
				input.mi.dy = y;
				input.mi.mouseData = 0;
				input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
				SendInput(1, &input, sizeof(input));
			}

			void RelativeMouseMove(int x, int y)
			{
				INPUT input;
				input.type = INPUT_MOUSE;
				input.mi.dx = x;
				input.mi.dy = y;
				input.mi.mouseData = 0;
				input.mi.dwFlags = MOUSEEVENTF_MOVE;
				SendInput(1, &input, sizeof(input));
			}

			void MouseWheel(int amount)
			{
				INPUT input;
				input.type = INPUT_MOUSE;
				input.mi.mouseData = amount;
				input.mi.dwFlags = MOUSEEVENTF_WHEEL;
				SendInput(1, &input, sizeof(input));
			}

			void LeftMouseDown()
			{
				SimulateMousePress(WM_LBUTTONDOWN, MK_LBUTTON);
			}

			void LeftMouseUp()
			{
				SimulateMousePress(WM_LBUTTONUP, 0);
			}

			void RightMouseDown()
			{
				SimulateMousePress(WM_RBUTTONDOWN, MK_RBUTTON);
			}

			void RightMouseUp()
			{
				SimulateMousePress(WM_RBUTTONUP, 0);
			}
		}
	}
#endif