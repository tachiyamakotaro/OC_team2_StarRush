#include "stdafx.h"
#include "Stage.h"

bool Stage::Start()
{
	m_modelRender.Init("Assets/modelData/kariStage.tkm");
	return true;
}

void Stage::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
