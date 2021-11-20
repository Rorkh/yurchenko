#include "yurchenko.hpp"

namespace yurchenko
{
	//! Simulates key down event
	/*!
		\param key an integer argument
	*/
	void KeyDown(int key)
	{
		#ifdef __linux__
			yurchenko::linux::KeyDown(key);
		#elif defined(_WIN32)
			yurchenko::windows::KeyDown(key);
		#elif defined(__APPLE__)
			yurchenko::macos::KeyDown(key);
		#endif
	}

	//! Simulates key up event
	/*!
		\param key an integer argument
	*/
	void KeyUp(int key)
	{
		#ifdef __linux__
			yurchenko::linux::KeyUp(key);
		#elif defined(_WIN32)
			yurchenko::windows::KeyUp(key);
		#elif defined(__APPLE__)
			yurchenko::macos::KeyUp(key);
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
			yurchenko::linux::GetMousePosition(x, y);
		#elif defined(_WIN32)
			yurchenko::windows::GetMousePosition(x, y);
		#elif defined(__LINUX__)
			yurchenko::macos::GetMousePosition(x, y);
		#endif
	}

	//! Checks if key pressed
	/*!
		\param key an integer argument
	*/
	bool IsKeyPressed(int key)
	{
		#ifdef __linux__
			return yurchenko::linux::IsKeyPressed(key);
		#elif defined(_WIN32)
			return yurchenko::windows::IsKeyPressed(key);
		#endif
	}

	//! Moves mouse
	/*!
		\param x an integer argument
		\param y an integer argument
		\param relative an boolean
	*/
	void MouseMove(int x, int y)
	{
		#ifdef __linux__
			yurchenko::linux::MouseMove(x, y);
		#elif defined(_WIN32)
			yurchenko::windows::MouseMove(x, y);
		#endif
	}
	
	//! Moves mouse relatively
	/*!
		\param x an integer argument
		\param y an integer argument
	*/
	void RelativeMouseMove(int x, int y)
	{
		#ifdef __linux__
			yurchenko::linux::RelativeMouseMove(x, y);
		#elif defined(_WIN32)
			yurchenko::windows::RelativeMouseMove(x, y);
		#endif
	}

	//! Simulates mouse wheel event
	/*!
		\param amount an integer argument
	*/
	void MouseWheel(int amount)
	{
		#ifdef __linux__
			yurchenko::linux::MouseWheel(amount);
		#elif defined(_WIN32)
			yurchenko::windows::MouseWheel(amount);
		#endif
	}

	//! Simulates left mouse down event
	void LeftMouseDown()
	{
		#ifdef __linux__
			yurchenko::linux::LeftMouseDown();
		#elif defined(_WIN32)
			yurchenko::windows::LeftMouseDown();
		#endif
	}

	//! Simulates left mouse up event
	void LeftMouseUp()
	{
		#ifdef __linux__
			yurchenko::linux::LeftMouseUp();
		#elif defined(_WIN32)
			yurchenko::windows::LeftMouseUp();
		#endif
	}

	//! Simulates right mouse down event
	void RightMouseDown()
	{
		#ifdef __linux__
			yurchenko::linux::RightMouseDown();
		#elif defined(_WIN32)
			yurchenko::windows::RightMouseDown();
		#endif
	}

	//! Simulates left mouse up event
	void RightMouseUp()
	{
		#ifdef __linux__
			yurchenko::linux::RightMouseUp();
		#elif defined(_WIN32)
			yurchenko::windows::RightMouseUp();
		#endif
	}
}