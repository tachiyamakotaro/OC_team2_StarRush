#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	//モデルを初期化する。
	m_modelRender.Init("Assets/modelData/Player/Player.tkm");

	//モデルの大きさ変更
	m_modelRender.SetScale({ 0.6f,0.6f,0.6f });

	//プレイヤーの初期地点
	m_position.x = 0.0f;
	m_position.y = 0.0f;
	m_position.z = -250.0f;

	m_characterController.Init(25.0f, -10.0f, m_position);
}

Player::~Player()
{

}

void Player::Update()
{
	//移動処理。
	Move();

    //モデルを更新する。
	m_modelRender.Update();
}

void Player::Move()
{
	//xzの移動速度を0.0fにする。
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.y = 0.0f;

	//左スティックの入力量を取得。
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//左スティックの入力量と150.0fを乗算。
	m_moveSpeed.x += stickL.x * 150.0f;
	m_moveSpeed.y += stickL.y * 150.0f;

	//移動範囲の制限
	//x軸
	if (m_position.x < -1200.0f) {
		m_position.x = -1200.0f;
		m_characterController.SetPosition(m_position);
	}
	else if (m_position.x > 1200.0f) {
		m_position.x = 1200.0f;
		m_characterController.SetPosition(m_position);
	}
	//y軸
	if (m_position.y < -600.0f) {
		m_position.y = -600.0f;
		m_characterController.SetPosition(m_position);
	}
	else if (m_position.y > 800.0f) {
		m_position.y = 800.0f;
		m_characterController.SetPosition(m_position);
	}
	//キャラクターコントローラーを使って座標を移動させる。
	m_position = m_characterController.Execute(m_moveSpeed, 1.0f / 6.0f);

	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_position);
}


void Player::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}



