#pragma once

class Player:public IGameObject
{
public:
	Player();
	~Player();
	//更新処理。
	void Update();
	//描画処理。
	void Render(RenderContext& renderContext);
	//移動処理。
	void Move();
	const Vector3& GetPosition()const {
		return m_position;
	}
    
	//メンバ変数。
private:
	ModelRender m_modelRender;   //モデルレンダー。
	Vector3     m_position;      //座標。
	CharacterController m_characterController;
	Vector3 m_moveSpeed;
	Quaternion m_rotation;
	int m_playerState = 0;

};

