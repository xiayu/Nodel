#pragma once
#include "Nodel.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class SandBox2D : public Nodel::Layer
{
public:
	SandBox2D();
	virtual ~SandBox2D();

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnUpdate(Nodel::TimeStep ts) override;
	virtual void OnRender() override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(Nodel::Event& e) override;
private:
	Nodel::OrthographicCamera m_Camera;
	Nodel::Ref<Nodel::CameraController> m_CameraController;
	
	// Temp
	Nodel::Ref<Nodel::VertexArray> m_SquareVA;
	Nodel::Ref<Nodel::Shader> m_FlatColorShader;

	Nodel::Ref<Nodel::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};

