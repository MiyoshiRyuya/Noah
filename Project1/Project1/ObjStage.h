#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�u���b�N���w�i
class CObjStage :public CObj
{
public:
	CObjStage() {};
	~CObjStage() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	//void BlockHit(
	//	float* x, float* y, bool scroll_on,
	//	bool* up, bool* fown, bool* left, bool* rihgt,
	//	float* vx, float* vy, int* bt
	//);
	////��l���ƕǂ̌�������
	//bool HeroBlockCrossPoint(
	//	float x, float y, float vx, float vy,
	//	float* out_px, float* out_py, float* out_len
	//);

private:
	//void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	//int m_map[10][100];	//�}�b�v���

	float m_scroll;		//���E�X�N���[��

	//float Dot(float ax, float ay, float bx, float by);		//����
	//float Cross(float ax, float ay, float bx, float by);	//�O��
	////���Ɛ��̌�������
	//bool CObjBlock::LineCrossPoint(
	//	float a1x, float a1y, float a2x, float a2y,
	//	float b1x, float b1y, float b2x, float b2y,
	//	float* out_px, float* out_py
	//);
};
