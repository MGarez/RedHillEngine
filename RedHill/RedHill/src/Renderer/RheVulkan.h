#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


class RheVulkan
{
public:
	RheVulkan(){}
	~RheVulkan(){}

	void Run();

private:

	void InitWindow();
	void InitVulkan();
	void MainLoop();
	void Cleanup();



	void CreateInstance();

	GLFWwindow* window= nullptr;
	VkInstance instance = nullptr;

	const int16_t default_width = 800;
	const int16_t default_height = 600;

	
};

