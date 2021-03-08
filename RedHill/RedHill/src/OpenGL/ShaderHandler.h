#pragma once

#include <string>
#include <GLAD/glad.h> 

class ShaderHandler
{
private:
	const char* vertexFolderPath = "./src/Shaders/GLSL/";
	const char* fragmentFolderPath = "./src/Shaders/GLSL/";
public:
	//ID del programa
	GLuint ID;
	// constructor que lee y construye los shaders
	ShaderHandler(const char* vertexName, const char* fragmentName);
	//usa/activa el programa
	void use()const;
	void cleanup()const;
	//Funciones definicion uniformes
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;



	

};

