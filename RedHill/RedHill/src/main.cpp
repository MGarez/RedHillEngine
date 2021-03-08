#include <iostream>

#include "OpenGL/GraphicsOGL.h"

enum GRAPHICS_API{d11,d12,vk,ogl};

int main(int argc, char** argv)
{
	GraphicsOGL* app {};

	app->HelloTriangleDemo();

	delete app;

	return EXIT_SUCCESS;
}