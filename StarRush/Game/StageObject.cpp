#include "stdafx.h"
#include "StageObject.h"

StageObject::~StageObject()
{
}

bool StageObject::Start()
{
	m_modelRender.Init("Assets/modelData/Stage/Wall/Wall.tkm");
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.SetScale(m_scale);

	return true;
}

void StageObject::Update()
{

}

void StageObject::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
