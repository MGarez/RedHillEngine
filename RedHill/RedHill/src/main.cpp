#include <iostream>
#include <stdexcept>

#include "Renderer/RheVulkan.h"

int main()
	{

	try
	{
		RheVulkan app;
		app.Run();
		std::cin.get();
	}
	catch(const std::exception & e){
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}
    return EXIT_SUCCESS;
}