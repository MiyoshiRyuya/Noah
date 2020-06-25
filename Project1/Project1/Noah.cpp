//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "Noah.h"
#include "main.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�ʒu���X�ύX�p
void CObjNoah::SetX(float x)
{
	m_px = x;
}
//�ʒu���Y�ύX�p
void CObjNoah::SetY(float y)
{
	m_py = y;
}

//�C�j�V�����C�Y
void CObjNoah::Init()
{
	m_px = 100;
	m_py = ((WINDOW_SIZE_H + CHAR_SIZE32) / 2) ;
	m_vx = 0.1f;
	m_vy = 0.1f;

	SpeedCount1 = 0;
	SpeedCount2 = 0;
	SpeedCount3 = 0;
	SpeedCount4 = 0;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, CHAR_SIZE32, CHAR_SIZE32, ELEMENT_PLAYER, OBJ_NOAH, 1);

}

//�A�N�V����
void CObjNoah::Action()
{

	//�ړ���������
	if (Input::GetVKey(VK_RIGHT)) {
		SpeedCount1++;
		m_px += m_vx;
		if (SpeedCount1 % 10 == 0)
		{
			m_vx += 0.5;
		}
		if (SpeedCount1 >= 60)
		{
			SpeedCount1 = 0;
		}

	}else{
		m_vx = 0.1;
	}
	if (Input::GetVKey(VK_LEFT)) {
		m_px -= m_vx;
		SpeedCount1++;
	}
	if (Input::GetVKey(VK_UP)) {
		m_py -= m_vy;
		SpeedCount1++;
	}
	if (Input::GetVKey(VK_DOWN)) {
		m_py += m_vy;
		SpeedCount4++;
	}

	//��l���@���̈�O�ɍs���Ȃ�����
	if (m_px + CHAR_SIZE32 > WINDOW_SIZE_W)
	{
		m_px = WINDOW_SIZE_W - CHAR_SIZE32;//�͂ݏo�Ȃ��ʒu�Ɉړ�������
	}
	if (m_py + CHAR_SIZE32 > WINDOW_SIZE_H)
	{
		m_py = WINDOW_SIZE_H - CHAR_SIZE32;
	}
	if (m_py < 0.0f)
	{
		m_py = 0.0f;
	}
	if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px, m_py);
}

//�h���[
void CObjNoah::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = CHAR_SIZE32;
	src.m_bottom = CHAR_SIZE32;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = CHAR_SIZE32 + m_px;
	dst.m_bottom = CHAR_SIZE32 + m_py;

	Draw::Draw(1, &src, &dst, c, 0.0f);
}