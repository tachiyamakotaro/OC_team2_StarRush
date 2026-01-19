#pragma once
#include "level3DRender/LevelRender.h"

class Player;
class StageManager;

class Stage :public IGameObject
{
public:
	bool Start() override;
	void Update() override;
	void LevelSetting();
	void SetPosition(const Vector3& pos)
	{
		m_pos =pos ;
	}
	void Render(RenderContext& rc) override;

private:
	ModelRender m_modelRender;
	LevelRender m_levelRender;
	Vector3 m_pos;

	Player* m_player = nullptr;
	StageManager* m_stageMana = nullptr;
};

