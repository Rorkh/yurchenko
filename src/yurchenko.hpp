#ifdef _WIN32
	#include "os/windows.hpp"
#elif defined(__linux__)
	#include "os/linux.hpp"
#elif defined(__APPLE__)
	#include "os/macos.hpp"
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