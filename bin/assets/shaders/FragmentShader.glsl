#version 460 core

in vec2 B_UV;

out vec4 O_Result;

layout (location = 3) uniform bool U_UseTexture;
layout (location = 4) uniform sampler2D U_Texture;
layout (location = 5) uniform vec3 U_Color;

void main()
{
    const vec4 v_color = vec4(U_Color, 1.0f);
    const vec4 v_texture = texture(U_Texture, B_UV);
    const vec4 v_result = U_UseTexture ? v_texture : v_color;
    O_Result = v_result;
}
