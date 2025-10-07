#include "engine/engine.hpp"
#include "engine/shader/shader_program.hpp"
#include "engine/utils/file_utils.hpp"

int main()
{
	const Window window{ "connogge" };
	const Renderer renderer{};

	const String vertex_source{ File::LoadAsString("") };
	const Shader vertex_shader{ ShaderType::VERTEX };
	vertex_shader.SetSource(vertex_source);
	vertex_shader.Compile();

	const String fragment_source{ File::LoadAsString("") };
	const Shader fragment_shader{ ShaderType::FRAGMENT };
	fragment_shader.SetSource(fragment_source);
	fragment_shader.Compile();

	const ShaderProgram shader_program{};
	shader_program.AttachShader(vertex_shader);
	shader_program.AttachShader(fragment_shader);
	shader_program.Link();

	List<Vertex> vertices{};
	vertices.push_back({ { -0.5f, +0.5f, 0.0f }, { 0.0f, 1.0f } });
	vertices.push_back({ { -0.5f, -0.5f, 0.0f }, { 0.0f, 0.0f } });
	vertices.push_back({ { +0.5f, -0.5f, 0.0f }, { 1.0f, 0.0f } });
	vertices.push_back({ { +0.5f, +0.5f, 0.0f }, { 1.0f, 1.0f } });

	List<GLuint> indices{};
	indices.emplace_back(0);
	indices.emplace_back(1);
	indices.emplace_back(2);
	indices.emplace_back(2);
	indices.emplace_back(3);
	indices.emplace_back(0);

	const Mesh mesh{ vertices, indices };

	while (!window.ShouldClose())
	{
		Events::PollAll();

		renderer.Viewport({ 0, 0 }, window.GetSize());
		renderer.ClearColor({ 0.65f, 1.0f, 0.65f });
		renderer.ClearBuffer();

		renderer.Render(mesh);

		window.SwapBuffers();
	}
}
