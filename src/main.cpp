#include "engine/system/window.hpp"
#include "engine/graphics/renderer.hpp"
#include "engine/graphics/vertex_array.hpp"
#include "engine/graphics/vertex_buffer.hpp"
#include "engine/graphics/element_buffer.hpp"

int main()
{
	const Window window{ "green" };
	const Renderer renderer{};

	const VertexArray vertex_array{};
	const VertexBuffer vertex_buffer{};
	const ElementBuffer element_buffer{};

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

	vertex_buffer.Data(vertices);
	element_buffer.Data(indices);

	vertex_array.SetVertexBuffer(vertex_buffer, sizeof(Vertex));
	vertex_array.SetElementBuffer(element_buffer);

	vertex_array.AddAttribute(0, 3);
	vertex_array.AddAttribute(1, 2);

	while (!window.ShouldClose())
	{
		Window::PollEvents();

		window.MakeCurrent();

		renderer.Viewport({ 0, 0 }, window.GetSize());
		renderer.ClearColor({ 0.65f, 1.0f, 0.65f });
		renderer.ClearBuffer();

		renderer.Render(vertex_array, indices);

		window.SwapBuffers();
	}
}
