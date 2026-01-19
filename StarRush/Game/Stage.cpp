#include "stdafx.h"
#include "Stage.h"
#include"Player.h"
#include"StageObject.h"

bool Stage::Start()
{
	LevelSetting();
	return true;
}

void Stage::LevelSetting()
{
	m_levelRender.Init("Assets/levelData/Stage.tkl", [&](LevelObjectData& objData)
		{
			if (objData.EqualObjectName(L"Wall"))
			{
				m_stageObject = NewGO<StageObject>(0, "stageObject");
				m_stageObject->SetPosition(objData.position);
				m_stageObject->SetRotation(objData.rotation);
				m_stageObject->SetScale(objData.scale);
				return true;
			}

			if (objData.EqualObjectName(L"Player"))
			{
				m_player = NewGO<Player>(0,"player");
				m_player->SetPosition(objData.position);
				m_player->SetRotation(objData.rotation);
				m_player->SetScale(objData.scale);
				return true;
			}
			return false;
		});
}

void Stage::Update()
{
	m_levelRender.Update();
}

void Stage::Render(RenderContext& rc)
{
	m_levelRender.Draw(rc);
	//m_modelRender.Draw(rc);
}
