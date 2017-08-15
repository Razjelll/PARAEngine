#version 330

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormals;
layout(location = 2) in vec2 inUV;

uniform mat4 MVP;

void main()
{
    gl_Position = MVP * vec4(inPosition, 1);
}
