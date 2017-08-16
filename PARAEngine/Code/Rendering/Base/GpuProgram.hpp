#ifndef __PARA_GPU_PROGRAM__
#define __PARA_GPU_PROGRAM__
#pragma once
#include <iostream>
#include <vector>
#include <map>

#include "../../Core/Resource.hpp"

namespace Para
{
	enum class UniformType
	{
		VEC2,
		VEC3,
		VEC4,
		MAT3,
		MAT4
	};

	enum class ShaderType
	{
		VERTEX_SHADER,
		FRAGMENT_SHADER,
		GEOMETRY_SHADER
	};

	typedef unsigned int ShaderID;
	//TODO to mo¿e ulec zmianie, poniea¿ nie wiadomo jakiego typu s¹ identyfikatory programów w innych bibliotekach
	typedef unsigned int ProgramID;
	typedef unsigned int AttributeID;
	typedef unsigned int UniformID;

	class Uniform
	{
	public:
		Uniform(const std::string& name, UniformType type) : m_name(name), m_type(type) {}
		virtual ~Uniform() {}
		const UniformID getID() const { return m_id; }
		const std::string getName() const { return m_name; }
		const UniformType getType() const { return m_type; }

	protected:
		UniformID m_id;
		std::string m_name;
		UniformType m_type;
	};

	/*class Shader
	{
	public:
	Shader(ShaderType type, std::string name) : m_type(type), m_name(name) {}
	virtual ~Shader() {}
	const ShaderID getID() const { return m_id; }
	const std::string getName() const { return m_name; }
	const ShaderType getType() const { return m_type; }
	protected:
	ShaderID m_id;
	std::string m_name;
	ShaderType m_type;
	};*/

	class Shader : public Resource
	{
	public:
		Shader(ShaderType shaderType, const std::string& name = NULL, ResourceListener* listener = NULL) : Resource(name, listener), m_shader_type(shaderType)
		{
			m_type = ResourceType::SHADER;
		}
		~Shader() {}

		ShaderID getID() { return m_id; }
		ShaderType getShaderType() { return m_shader_type; }
		void setShaderType(ShaderType shaderType) { m_shader_type = shaderType; }
	protected:
		ShaderID m_id; //TODO to mo¿e byæzast¹pione guid
		ShaderType m_shader_type;

	protected:
		virtual bool loadResource(const std::string& filename) = 0;
		virtual bool unloadResource() = 0;

		
	};


	class GpuProgram
	{
	public:
		GpuProgram();
		~GpuProgram();

		virtual void bind() = 0;
		virtual void unbind() = 0;
		virtual void addAttribute(const std::string& attribute) = 0;
		virtual void addUniform(const std::string& uniform, UniformType uniformType) = 0;
		virtual AttributeID getAttribute(const std::string& attribute) { return m_attributes.find(attribute)->second; }
		virtual UniformID getUniform(const std::string& uniform) { return m_uniforms.find(uniform)->second->getID(); }


		ProgramID getProgramID() { return m_program_id; }
	protected:
		ProgramID m_program_id;
		//TODO zobaczyæ, czy wektor bêdzie tutaj odpowiedni

		std::vector<Shader*> m_shaders;
		std::map<std::string, AttributeID> m_attributes;
		std::map < std::string, Uniform*> m_uniforms;

	};
}


#endif //__PARA_GPUT_PROGRAM__