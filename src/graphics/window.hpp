#ifndef _WINDOW_HPP
#define _WINDOW_HPP

#include <string>

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

class Window
{
public:
	explicit Window(const std::string &title);
	
	~Window();
	
	void pollEvents() const;
	
	void swapBuffers() const;
	
	bool shouldClose() const;
	
	const glm::ivec2 &getSize() const;
	
	void callbackSetSize(int width, int height);
	
private:
	GLFWwindow *handle;
	glm::ivec2 size;
};

#endif // _WINDOW_HPP
