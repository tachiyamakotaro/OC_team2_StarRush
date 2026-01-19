#include "stdafx.h"
#include "Stage.h"
#include"StageManager.h"
#include"Player.h"

bool Stage::Start()
{
	LevelSetting();
	return true;
}

void Stage::LevelSetting()
{
	m_levelRender.Init("Assets/levelData/StageLevel.tkl", [&](LevelObjectData& objData)
		{
			if (objData.EqualObjectName(L"Stage"))
			{
				m_stageMana = NewGO<StageManager>(0);
				m_stageMana->SetPosition(objData.position);
				m_stageMana->SetRotation(objData.rotation);
				m_stageMana->SetScale(objData.scale);
				return true;
			}

			if (objData.EqualObjectName(L"Player"))
			{
				m_player = NewGO<Player>(0,"player");
				m_player->SetPosition(objData.position);
			}
			return false;
		});
}

void Stage::Update()
{

}

void Stage::Render(RenderContext& rc)
{
	m_levelRender.Draw(rc);
	//m_modelRender.Draw(rc);
}
