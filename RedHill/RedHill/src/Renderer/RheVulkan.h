#pragma once

#define GLFW_INCLUDE_VULKAN
#include <optional>
#include <vector>
#include <GLFW/glfw3.h>


class RheVulkan
{
public:
	RheVulkan() = default;
	~RheVulkan() = default;

	void Run();

private:

	struct QueueFamilyIndices
	{
		std::optional<uint32_t> graphicsFamily;

		bool isComplete()
		{
			return graphicsFamily.has_value();
		}
	};

	void InitWindow();
	void InitVulkan();
	void MainLoop();
	void Cleanup();



	void CreateInstance();
	bool CheckValidationLayersSupport() const;
	void SetupDebugMessenger();
	void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	void PickPhysicalDevice();


	std::vector<const char*> GetRequiredExtensions() const;
	bool IsDeviceSuitable(const VkPhysicalDevice & device);
	QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);

	GLFWwindow* window= nullptr;
	VkInstance instance = nullptr;
	VkDebugUtilsMessengerEXT debugMessenger = nullptr;

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

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



