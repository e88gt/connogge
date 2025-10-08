#include "engine/engine.hpp"
#include "engine/screen/camera_3d.hpp"
#include "engine/shader/shader_program.hpp"
#include "engine/utils/file_utils.hpp"
#include "engine/utils/time.hpp"
#include "engine/utils/transformation_3d.hpp"

#include "engine/utils/time.hpp"

int main()
{
	const Window window{ "connogge" };
	const Renderer renderer{};

	const String vertex_source{ File::LoadAsString("assets/shaders/VertexShader.glsl") };
	const Shader vertex_shader{ ShaderType::VERTEX };
	vertex_shader.SetSource(vertex_source);
	vertex_shader.Compile();

	const String fragment_source{ File::LoadAsString("assets/shaders/FragmentShader.glsl") };
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

	Camera3D camera{};
	Transformation3D transformation{};

	camera.Position().z = 1.0f;

	const Mesh mesh{ vertices, indices };

	double last_time = Time::Nano();

	while (!window.ShouldClose())
	{
		const double current_time = Time::Nano();
		const double delta = (current_time - last_time) / Time::NS_PER_SEC;
		last_time = current_time;

		Events::PollAll();

		renderer.Viewport({ 0, 0 }, window.GetSize());
		renderer.ClearColor({ 0.65f, 1.0f, 0.65f });
		renderer.ClearBuffer();

		transformation.Rotation().x += 50.0f * delta;
		shader_program.SetUniformMatrix4f(0, transformation.GetTransformation());
		shader_program.SetUniformMatrix4f(1, camera.GetViewMatrix());
		shader_program.SetUniformMatrix4f(2, camera.GetProjection(window.GetSize()));
		shader_program.Use();
		renderer.Render(mesh);

		window.SwapBuffers();
	}
}
