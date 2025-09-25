#include "main.hpp"

#include <iostream>

#include "window.hpp"

int main()
{
	Window window = Window{ "" };
	
	while(!window.shouldClose())
	{
		window.pollEvents();
		
		window.swapBuffers();
	}
	
	window.~Window();
	
	return 0;
}
