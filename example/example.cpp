#include "../src/yurchenko.hpp"
#include <iostream>

int main()
{
	int x, y;
	yurchenko::GetMousePosition(&x, &y);

	std::cout << x << std::endl;

	return 0;
}