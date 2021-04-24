#include "RheVulkan.h"

#include <stdexcept>

void RheVulkan::Run()
{
	InitWindow();
	InitVulkan();
	MainLoop();
	Cleanup();
}

void RheVulkan::InitVulkan()
{
	CreateInstance();
}

void RheVulkan::InitWindow()
{
	glfwInit();
	
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(default_width, default_height, "Red Hill", nullptr, nullptr);
}

void RheVulkan::MainLoop()
{
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
}

void RheVulkan::Cleanup()
{
	vkDestroyInstance(instance, nullptr);
	glfwDestroyWindow(window);
	glfwTerminate();
}

void RheVulkan::CreateInstance()
{
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Prueba Vulkan";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "Red Hill";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo instanceInfo{};
	instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceInfo.pApplicationInfo = &appInfo;

	uint32_t glfwExtensionsCount = 0;
	const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionsCount);;

	instanceInfo.enabledExtensionCount = glfwExtensionsCount;
	instanceInfo.ppEnabledExtensionNames = glfwExtensions;
	instanceInfo.enabledLayerCount = 0;

	if(vkCreateInstance(&instanceInfo, nullptr, &instance) != VK_SUCCESS)
	{
		throw std::runtime_error("error creating instance");
	}

	
	
}
