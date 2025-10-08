#version 460 core

layout (location = 0) in vec3 I_Position;
layout (location = 1) in vec2 I_UV;

out vec2 B_UV;

layout (location = 0) uniform mat4 U_Object;
layout (location = 1) uniform mat4 U_View;
layout (location = 2) uniform mat4 U_Proj;

void main()
{
    B_UV = I_UV;
    const vec4 result = U_Object * vec4(I_Position, 1.0f);
    // const vec4 result = vec4(I_Position, 1.0f);
    gl_Position = result;
}
