#include "stdafx.h"
#include "Game.h"
#include "Stage.h"
#include "GameCamera.h"
#include"Player.h"

bool Game::Start()
{
	//m_modelRender.Init("Assets/modelData/Player/Player.tkm");
	m_stage = NewGO<Stage>(0,"stage");
	m_gameCamera = NewGO<GameCamera>(1, "gameCamera");
	//m_player = NewGO<Player>(0, "player");
	return true;
}

void Game::Update()
{
	// g_renderingEngine->DisableRaytracing();
	m_modelRender.Update();
}

void Game::Render(RenderContext& rc)
{
	//m_modelRender.Draw(rc);
}