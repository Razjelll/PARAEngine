#include "GLGpuProgram.hpp"
#include "../../Utils/FileReader.hpp"
#include <assert.h>

const std::string SHADERS_PATH = "../Shaders/";

#define GL_CHECK_ERRORS assert(glGetError()== GL_NO_ERROR);

GLShader::GLShader(ShaderType shaderType, const std::string& name) : Shader(shaderType, name)
{
	std::string shaderSource;
	FileReader::read(SHADERS_PATH + name, shaderSource);
	loadFromString(shaderType, shaderSource);
}

GLShader::~GLShader() 
{
	glDeleteShader(m_id);
}

const GLenum GLShader::getGLShaderType(const ShaderType shaderType) const
{
	switch (shaderType)
	{
	case ShaderType::VERTEX_SHADER:
		return GL_VERTEX_SHADER;
	case ShaderType::GEOMETRY_SHADER:
		return GL_GEOMETRY_SHADER;
	case ShaderType::FRAGMENT_SHADER:
		return GL_FRAGMENT_SHADER;
	}
}

void checkErrors() {
	GLenum err(glGetError());

	while (err != GL_NO_ERROR) {
		std::string error;

		switch (err) {
		case GL_INVALID_OPERATION:      error = "INVALID_OPERATION";      break;
		case GL_INVALID_ENUM:           error = "INVALID_ENUM";           break;
		case GL_INVALID_VALUE:          error = "INVALID_VALUE";          break;
		case GL_OUT_OF_MEMORY:          error = "OUT_OF_MEMORY";          break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:  error = "INVALID_FRAMEBUFFER_OPERATION";  break;
		}

		std::cerr << "GL_" << error.c_str() << " - " << std::endl;
		err = glGetError();
	}
}

void GLShader::loadFromString(ShaderType shaderType, const std::string& source)
{
	GLenum type = getGLShaderType(shaderType);
	GL_CHECK_ERRORS;
	GLuint shaderID = glCreateShader(type);
	const char* shaderSource = source.c_str();
	glShaderSource(shaderID, 1, &shaderSource, NULL);

	GL_CHECK_ERRORS;
	m_id = shaderID;
#define DEBUG
#if defined(DEBUG)
	GLint status;
	glCompileShader(shaderID);
	GL_CHECK_ERRORS;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar *infoLog = new GLchar[infoLogLength];
		glGetShaderInfoLog(shaderID, infoLogLength, NULL, infoLog);
		std::cerr << "Compile log: " << infoLog << std::endl;
		delete[] infoLog;
	}
	else {
		std::cout << "Compile successful" << std::endl;
	}
	GL_CHECK_ERRORS;
	
#endif
}

//TODO ta metoda zostanie usuniêta, albo to wy¿ej zostanie do niej wrzucone
bool GLShader::validateShader()
{
	GLint status;
	glCompileShader(m_id);
	glGetShaderiv(m_id, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(m_id, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* infoLog = new GLchar[infoLogLength];
		glGetShaderInfoLog(m_id, infoLogLength, NULL, infoLog);
		std::cerr << "Validate log: " << infoLog << std::endl;
		delete[] infoLog;
		return false;
	}
	
	return true;
}

GLUniform::GLUniform(const std::string& name, UniformType type, ProgramID programID) : Uniform(name, type)
{
	m_id = glGetUniformLocation(programID, name.c_str());
}

GLUniform::~GLUniform()
{

}

GLGpuProgram::GLGpuProgram()
{
	m_program_id = glCreateProgram();
}


GLGpuProgram::~GLGpuProgram()
{
	for (int i = 0; i < m_shaders.size(); i++)
	{
		delete m_shaders[i];
	}

	//TODO zrobic tutaj usuwanie wszystkich uniformów

	glDeleteProgram(m_program_id);
}

void GLGpuProgram::create()
{
	//TODO zobaczyæ, czy da rade bez tego
	GL_CHECK_ERRORS;
	glLinkProgram(m_program_id);
	checkErrors();
#if defined(DEBUG)
	GLint status;
	glGetProgramiv(m_program_id, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(m_program_id, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* infoLog = new GLchar[infoLogLength];
		glGetProgramInfoLog(m_program_id, infoLogLength, NULL, infoLog);
		std::cerr << "Link error log: " << infoLog << std::endl;
		delete[] infoLog;
	}
	else
	{
		std::cout << "Link succesfull" << std::endl;
	}
#endif
}

void GLGpuProgram::addShader(Shader* shader)
{
	m_shaders.push_back(shader);
	glAttachShader(m_program_id, shader->getID());
}

bool GLGpuProgram::deleteShader(const std::string& shaderName)
{
	for (int i = 0; i < m_shaders.size(); i++)
	{
		if (shaderName == m_shaders[i]->getName())
		{
			Shader* shader = m_shaders[i];
			glDeleteShader(shader->getID());
			m_shaders.erase(m_shaders.begin() + i);
			delete shader;
			return true;
		}
	}
	return false;
}

//TODO mo¿na to wrzucic do wspólnej metody
bool GLGpuProgram::deleteShader(ShaderID shaderID)
{
	for (int i = 0; i < m_shaders.size(); i++)
	{
		if (shaderID == m_shaders[i]->getID())
		{
			Shader* shader = m_shaders[i];
			glDeleteShader(shader->getID());
			m_shaders.erase(m_shaders.begin() + i);
			delete shader;
			return true;
		}
	}
	return false;
}

void GLGpuProgram::deleteProgram()
{
	glDeleteProgram(m_program_id);
}

void GLGpuProgram::bind()
{
	glUseProgram(m_program_id);
}

void GLGpuProgram::unbind()
{
	glUseProgram(NULL);
}

void GLGpuProgram::addAttribute(const std::string& attribute)
{
	
	m_attributes[attribute] = glGetAttribLocation(m_program_id, attribute.c_str());
}

void GLGpuProgram::addUniform(const std::string& uniform, UniformType type)
{
	m_uniforms[uniform] = new GLUniform(uniform, type, m_program_id);
}




