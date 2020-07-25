#include "SandBox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

SandBox2D::SandBox2D()
	:Layer("2d layer"), m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f })
{
	float aspectratio = 1280.0f / 720.0f;
	float zoomlevel = 1.0;
	m_Camera.SetProjection(-aspectratio * zoomlevel, aspectratio * zoomlevel, -zoomlevel, zoomlevel);
	m_CameraController = Nodel::CreateRef<Nodel::CameraController>(m_Camera);
	m_CameraController->SetZoomLevel(zoomlevel);

}

SandBox2D::~SandBox2D() {

}

void SandBox2D::OnAttach()
{
	m_CheckerboardTexture = Nodel::Texture2D::Create("assets/textures/Checkerboard.png");
}

void SandBox2D::OnDetach()
{
}

void SandBox2D::OnUpdate(Nodel::TimeStep ts)
{
	// Update
	m_CameraController->OnUpdate(ts);

	// Render
	Nodel::Renderer2D::ResetStats();
	{
		Nodel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Nodel::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		Nodel::Renderer2D::BeginScene((Nodel::OrthographicCamera&)m_CameraController->GetCamera());
		Nodel::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.1f, 1.0f, 0.3f, 1.0f });
		Nodel::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Nodel::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		Nodel::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
		Nodel::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture, 20.0f);
		Nodel::Renderer2D::EndScene();

		Nodel::Renderer2D::BeginScene((Nodel::OrthographicCamera&)m_CameraController->GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				Nodel::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		Nodel::Renderer2D::EndScene();
	}
}

void SandBox2D::OnRender()
{
}

void SandBox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");

	auto stats = Nodel::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void SandBox2D::OnEvent(Nodel::Event& e)
{
	m_CameraController->OnEvent(e);
}
