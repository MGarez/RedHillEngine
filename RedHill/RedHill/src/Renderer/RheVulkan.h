#pragma once

#define GLFW_INCLUDE_VULKAN
#include <vector>
#include <GLFW/glfw3.h>


class RheVulkan
{
public:
	RheVulkan() = default;
	~RheVulkan() = default;

	void Run();

private:

	void InitWindow();
	void InitVulkan();
	void MainLoop();
	void Cleanup();



	void CreateInstance();
	bool CheckValidationLayersSupport() const;
	void SetupDebugMessenger();
	void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);


	std::vector<const char*> GetRequiredExtensions() const;

	GLFWwindow* window= nullptr;
	VkInstance instance = nullptr;
	VkDebugUtilsMessengerEXT debugMessenger = nullptr;

	const int16_t default_width = 800;
	const int16_t default_height = 600;
	const std::vector<const char*> validationLayers = {
		"VK_LAYER_KHRONOS_validation"
	};

#ifdef _DEBUG
	const bool enableValidationLayers = true;
#else
	const bool enableValidationLayers = false;
#endif
	
};



