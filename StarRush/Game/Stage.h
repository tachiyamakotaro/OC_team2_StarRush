#pragma once
class Stage :public IGameObject
{
public:
	bool Start() override;
	void SetPosition(const Vector3& pos)
	{
		m_pos =pos ;
	}
	void Render(RenderContext& rc) override;

private:
	ModelRender m_modelRender;
	Vector3 m_pos;
};

