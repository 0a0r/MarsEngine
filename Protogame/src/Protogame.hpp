#pragma once

#include "Engine/Core/GameCore.hpp"

struct ShaderProgram;

class Protogame : public GameCore::IGameApp
{
public:
	Protogame() {}

	virtual void Startup() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void RenderScene() const override;

	void DrawFirstTriangle();

protected:
	ShaderProgram* sh = nullptr;
};