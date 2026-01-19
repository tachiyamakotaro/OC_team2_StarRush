#include "stdafx.h"
#include "StageManager.h"

StageManager::StageManager()
{

}

StageManager::~StageManager()
{

}

bool StageManager::Start()
{
	m_modelRender.Init("Assets/levelData/Stage.tkm");
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.SetScale(m_scale);
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());

	return true;
}

void StageManager::Update()
{

}

void StageManager::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}