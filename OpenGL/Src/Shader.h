#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader {

public:
	// shader program ID
	unsigned int m_shaderID;

	// reads and builds the shader
	Shader(const char* vertexPath, const char* fragmentPath);

	void CreateShader(unsigned int shaderType, const std::string& shaderSource);

	void CreateShaderProgram();

	// use/activate the shader
	void use();

	// utiltiy uniform functions
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string* name, bool value) const;
	void setFloat(const std::string*& name, float value) const;

};