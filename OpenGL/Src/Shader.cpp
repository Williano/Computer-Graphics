#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexCode, fragmentCode;
	std::ifstream vertexShaderFile, fragmentShaderFile;

	vertexShaderFile.exceptions(std::ios::failbit | std::ios::badbit);
	fragmentShaderFile.exceptions(std::ios::failbit | std::ifstream::badbit);

	try
	{
		// open files
		vertexShaderFile.open(vertexPath);
		fragmentShaderFile.open(fragmentPath);

		std::stringstream vertexShaderStream, fragmentShaderStream;

		// read file's buffer contents into streams
		vertexShaderStream << vertexShaderFile.rdbuf();
		fragmentShaderStream << fragmentShaderFile.rdbuf();

		vertexShaderFile.close();
		fragmentShaderFile.close();

		// convert stream into string
		vertexCode = vertexShaderStream.str();
		fragmentCode = fragmentShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
	}

	m_vertexShaderCode = vertexCode.c_str();
	m_fragmentShaderCode = fragmentCode.c_str();

}


void Shader::createShader(unsigned int shaderType, const std::string& shaderSource)
{

	const char* source = shaderSource.c_str();

	m_shaderID = glCreateShader(shaderType);
	glShaderSource(m_shaderID, 1, &source, NULL);
	glCompileShader(m_shaderID);

	glGetShaderiv(m_shaderID, GL_COMPILE_STATUS, &m_success);

	if (!m_success)
	{
		glGetShaderInfoLog(m_shaderID, 512, NULL, m_infoLog);
		std::cout << "ERROR::SHADER::COMPILATION FAILED\n" << m_infoLog << std::endl;

	}
}


void Shader::createShaderProgram(unsigned int shaderID)
{
	m_ShaderProgramID = glCreateProgram();
	glAttachShader(m_ShaderProgramID, shaderID);

	glGetProgramiv(m_ShaderProgramID, GL_LINK_STATUS, &m_success);
	if (!m_success)
	{
		glGetProgramInfoLog(m_ShaderProgramID, 512, NULL, m_infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << m_infoLog << std::endl;
	}

}


void Shader::linkShaderProgram()
{
	glLinkProgram(m_ShaderProgramID);
}


void Shader::useShaderProgram()
{
	glUseProgram(m_ShaderProgramID);
}


void Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(m_ShaderProgramID, name.c_str()), (int)value);
}


void Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(m_ShaderProgramID, name.c_str()), value);
}


void Shader::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(m_ShaderProgramID, name.c_str()), value);
}


void Shader::deleteShader()
{
	glDeleteShader(m_shaderID);
}


void Shader::deleteShaderProgram()
{
	glDeleteProgram(m_ShaderProgramID);
}