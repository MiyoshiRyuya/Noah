#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト:ブロック＆背景
class CObjStage :public CObj
{
public:
	CObjStage() {};
	~CObjStage() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	//void BlockHit(
	//	float* x, float* y, bool scroll_on,
	//	bool* up, bool* fown, bool* left, bool* rihgt,
	//	float* vx, float* vy, int* bt
	//);
	////主人公と壁の交差判定
	//bool HeroBlockCrossPoint(
	//	float x, float y, float vx, float vy,
	//	float* out_px, float* out_py, float* out_len
	//);

private:
	//void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	//int m_map[10][100];	//マップ情報

	float m_scroll;		//左右スクロール

	//float Dot(float ax, float ay, float bx, float by);		//内積
	//float Cross(float ax, float ay, float bx, float by);	//外積
	////線と線の交差判定
	//bool CObjBlock::LineCrossPoint(
	//	float a1x, float a1y, float a2x, float a2y,
	//	float b1x, float b1y, float b2x, float b2y,
	//	float* out_px, float* out_py
	//);
};
