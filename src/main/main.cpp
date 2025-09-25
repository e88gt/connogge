#include "main.hpp"

#include <iostream>

#include "window.hpp"

int main()
{
	Window_T window;
	
	window_create(&window);
	
	while(!window_should_close(&window))
	{
		window_poll_events(&window);
		
		window_swap_buffers(&window);
	}
	
	window_destroy(&window);
	
	return 0;
}
