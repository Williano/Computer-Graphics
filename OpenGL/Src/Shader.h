#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


const int LOG_SIZE = 512;

class Shader {

public:

	// reads and builds the shader
	Shader(const char* vertexPath, const char* fragmentPath);
	void createShader(unsigned int shaderType, const std::string& shaderSource);
	void deleteShader();
	void createShaderProgram(unsigned int shaderID);
	void linkShaderProgram();
	void useShaderProgram();
	void deleteShaderProgram();

	// utiltiy uniform functions
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;

private:

	unsigned int m_ShaderProgramID;
	const char* m_vertexShaderCode;
	const char* m_fragmentShaderCode;
	unsigned int m_shaderID;
	int m_success;
	char m_infoLog[LOG_SIZE];

};