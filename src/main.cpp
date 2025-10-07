#include "engine/system/events.hpp"
#include "engine/screen/window.hpp"
#include "engine/graphics/renderer.hpp"

int main()
{
	const Window window{ "green" };
	const Renderer renderer{};

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
