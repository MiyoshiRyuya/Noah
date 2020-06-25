#pragma once
#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjNoah : public CObj
{
public:
	CObjNoah() {};
	~CObjNoah() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー
	void SetX(float x);    //位置情報X変更用
	void SetY(float y);    //位置情報Y変更用

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

private:
	float m_px;      //主人公機のｘ方向移動用変数
	float m_py;      //主人公機のy方向移動用変数
	float m_vx;     //主人公機のｘ方向移動ベクトル用変数
	float m_vy;     //主人公機のｙ方向移動ベクトル用変数

	int SpeedCount1;
	int SpeedCount2;
	int SpeedCount3;
	int SpeedCount4;

	float rad;		//角度
	float kakud;
	float speed;

};