#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class GameCamera;
class BackGround;

class Game : public IGameObject
{
public:
	Game() {}
	~Game() {}
	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:
	Player* m_player;
	BackGround* m_backGround;
	ModelRender m_modelRender;
	Vector3 m_pos;
	GameCamera* m_gameCamera;
	Vector3* m_position;
};

