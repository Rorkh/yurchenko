#ifdef __APPLE__
	#include "../yurchenko.hpp"

	namespace yurchenko 
	{
		namespace macos
		{
			void KeyDown(int key)
			{
				CGEventSourceRef src = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);
				CGEventRef evt = CGEventCreateKeyboardEvent(src, (CGKeyCode) key, true);
				CGEventPost (kCGHIDEventTap, evt);
				CFRelease (evt); CFRelease (src);
			}

			void KeyUp(int key)
			{
				CGEventSourceRef src = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);
				CGEventRef evt = CGEventCreateKeyboardEvent(src, (CGKeyCode) key, false);
				CGEventPost (kCGHIDEventTap, evt);
				CFRelease (evt); CFRelease (src);
			}

			void GetMousePosition(int *x, int *y)
			{
				CGEventRef event = CGEventCreate(NULL);
				CGPoint cursor = CGEventGetLocation(event);
				CFRelease(event);
				*x = cursor.x;
				*y = cursor.y;
			}
		}
	}
#endif