#pragma once
#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjNoah : public CObj
{
public:
	CObjNoah() {};
	~CObjNoah() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[
	void SetX(float x);    //�ʒu���X�ύX�p
	void SetY(float y);    //�ʒu���Y�ύX�p

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

private:
	float m_px;      //��l���@�̂������ړ��p�ϐ�
	float m_py;      //��l���@��y�����ړ��p�ϐ�
	float m_vx;     //��l���@�̂������ړ��x�N�g���p�ϐ�
	float m_vy;     //��l���@�̂������ړ��x�N�g���p�ϐ�

	int SpeedCount1;
	int SpeedCount2;
	int SpeedCount3;
	int SpeedCount4;

	float rad;		//�p�x
	float kakud;
	float speed;

};