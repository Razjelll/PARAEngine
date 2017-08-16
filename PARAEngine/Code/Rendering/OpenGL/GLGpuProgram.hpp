#ifndef __PARA_GL_GPU_PROGRAM__
#define __PARA_GL_GPU_PROGRAM__

#pragma once

#include "../Base/GpuProgram.hpp"
#include "../OpenGL/OpenGL/include/glew.h"

namespace Para
{
	class GLUniform : public Uniform
	{
	public:
		GLUniform(const std::string& name, UniformType type, ProgramID programID);
		~GLUniform();
	};

	/*class GLShader : public Shader
	{
	public:
		GLShader(ShaderType type, const std::string& name);
		~GLShader();
	private:
		void loadFromString(ShaderType shaderType, const std::string& source);
		const GLenum getGLShaderType(const ShaderType shadertype) const;
		bool validateShader();
	};*/
	class GLShader : public Shader
	{
	public:
		GLShader(ShaderType type, const std::string& name = NULL, ResourceListener* listener = NULL);
		~GLShader();

	private:
		bool loadResource(const std::string& filename) override;
		bool unloadResource() override;

		bool loadFromString(const std::string& source);
		const GLenum getGLShaderType(const ShaderType shaderType) const;
		bool validateShader();
	};

	class GLGpuProgram : public GpuProgram
	{
	public:
		GLGpuProgram();
		~GLGpuProgram();

		void create();
		void addShader(Shader* shader);
		bool deleteShader(const std::string& shaderName);
		bool deleteShader(ShaderID shaderID);
		void deleteProgram(); //TODO zastanowiæ siê, czy to jest potrzebne
		void bind();
		void unbind();
		void addAttribute(const std::string& attribute);
		void addUniform(const std::string& uniform, UniformType type);

	};
}

#endif //__PARA_GL_GPU_PROGRAM__
