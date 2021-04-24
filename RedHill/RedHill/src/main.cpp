#include <iostream>
#include <stdexcept>

#include "Renderer/RheVulkan.h"

int main()
{
    RheVulkan app;

	try
	{
		app.Run();
	}
	catch(const std::exception & e){
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}
    return EXIT_SUCCESS;
}