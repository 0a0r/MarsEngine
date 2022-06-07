#pragma once

#include "Engine/Core/GameCore.hpp"

namespace Graphics
{
	class GLShaderProgram;
	class GLVertexBuffer;
}

class Protogame : public GameCore::IGameApp
{
public:
	Protogame() {}

	virtual void Startup() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void RenderScene() const override;

	void DrawFirstTriangle() const;

protected:
	Graphics::GLShaderProgram* sh = nullptr;
	Graphics::GLVertexBuffer* testVBO = nullptr;
};