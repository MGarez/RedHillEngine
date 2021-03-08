#include "ShaderHandler.h"


#include <sstream>
#include <fstream>
#include <iostream>

ShaderHandler::ShaderHandler(const char* vertexName, const char* fragmentName)
{
	std::string vertexTotalPath = vertexName;
	vertexTotalPath = vertexFolderPath + vertexTotalPath;

	std::string fragmentTotalPath = fragmentName;
	fragmentTotalPath = fragmentFolderPath + fragmentTotalPath;

	std::ifstream vertexFile, fragmentFile;
	std::stringstream ssVertex, ssFragment;
	std::string vertexCode, fragmentCode;

	vertexFile.open(vertexTotalPath, std::fstream::in);
	ssVertex << vertexFile.rdbuf();
	vertexCode = ssVertex.str();
	vertexFile.close();

	fragmentFile.open(fragmentTotalPath, std::fstream::in);
	ssFragment << fragmentFile.rdbuf();
	fragmentCode = ssFragment.str();
	fragmentFile.close();

	const GLchar* const cvertexCode = vertexCode.c_str();
	const GLchar* const cfragmentCode = fragmentCode.c_str();

	GLuint vertexProgram, fragmentProgram;

	vertexProgram = glCreateShader(GL_VERTEX_SHADER);
	fragmentProgram = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexProgram, 1, &cvertexCode, NULL);
	glShaderSource(fragmentProgram, 1, &cfragmentCode, NULL);

	glCompileShader(vertexProgram);
	glCompileShader(fragmentProgram);

	int success;
	char infoLog[512];

	glGetShaderiv(vertexProgram, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	glGetShaderiv(fragmentProgram, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	ID = glCreateProgram();
	glAttachShader(ID, vertexProgram);
	glAttachShader(ID, fragmentProgram);
	glLinkProgram(ID);
	// print linking errors if any
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	glDetachShader(ID, vertexProgram);
	glDetachShader(ID, fragmentProgram);

	glDeleteShader(vertexProgram);
	glDeleteShader(fragmentProgram);

}

void ShaderHandler::use()const
{
	glUseProgram(ID);
}

void ShaderHandler::cleanup()const
{
	glDeleteProgram(ID);
}


void ShaderHandler::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void ShaderHandler::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void ShaderHandler::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}