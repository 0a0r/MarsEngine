#pragma once

#include "Engine/Core/GameCore.hpp"

class Protogame : public GameCore::IGameApp
{
public:
	Protogame() {}

	virtual void Startup() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void RenderScene() const override;

	void DrawFirstTriangle();
};