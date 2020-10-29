#include "Window.h"

#include <iostream>

void	error(int error, const char* message)
{
	std::cerr << message << std::endl;
}

void GLAPIENTRY
MessageCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam)
{
	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
		(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
		type, severity, message);
}
namespace Core::Renderer
{
	Window::Window(RendererType type) : m_rendererType(type)
	{
	}

	bool Window::Init()
	{
		glfwSetErrorCallback(error);

		if (!glfwInit())
			return false;

		if (m_rendererType == RendererType::OpenGL)
		{
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		}
		else //vulkan
		{
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		}
		//glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

		const GLFWvidmode* videoMode{ glfwGetVideoMode(glfwGetPrimaryMonitor()) };

		m_window = glfwCreateWindow(videoMode->width, videoMode->height, "Voxel Engine", nullptr, nullptr);

		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, this);
		glfwSwapInterval(1);
		if (m_rendererType == RendererType::OpenGL)
		{
			if (!gladLoadGL(glfwGetProcAddress))
			{
				fprintf(stderr, "gladLoadGL failed. \n");
				return false;
			}
			glDebugMessageCallback(MessageCallback, 0);
		}
		else //vulkan
		{
			//TODO: possibly implement vulkan renderer
		}
	}

	void Window::SwapBuffers()
	{
		glfwSwapBuffers(m_window);
	}
}
