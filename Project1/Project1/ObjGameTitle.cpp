#pragma once
//�g�p����w�b�_�[�t�@�C��

#include"GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameTitle.h"
#include"main.h"
#include"GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�^�C�g��and���j���[�֘A-----------------------
#define LAVEL_TOP   0		//���x���̈�ԏ�(�X�^�[�g)

#define LAVEL_MID_M 1		//���j���[���x���̐^��()
#define LAVEL_BOT_M 2		//���j���[���x���̈�ԉ�()

#define LAVEL_BOT_T 1		//�^�C�g�����x���̈�ԉ�()

#define START_CUT_TOP		0.0f	//�^�C�g���摜�؂����
#define START_CUT_LEFT		0.0f	//�^�C�g���摜�؂��荶
#define START_CUT_RIGHT		1024.0f  //�^�C�g���摜�؂���E
#define START_CUT_BOTTOM	512.0f	//�^�C�g���摜�؂��艺

#define START_BUTTON_CUT_TOP	0.0f	//�{�^���؂����
#define START_BUTTON_CUT_LEFT	64.0f	//�{�^���؂��荶
#define START_BUTTON_CUT_RIGHT	64.0f	//�{�^���؂���E
#define START_BUTTON_CUT_BOTTOM	64.0f	//�{�^���؂��艺

#define END_BUTTON_CUT_TOP		0.0f	//�{�^���؂����
#define END_BUTTON_CUT_LEFT		0.0f	//�{�^���؂��荶
#define END_BUTTON_CUT_RIGHT	64.0f	//�{�^���؂���E
#define END_BUTTON_CUT_BOTTOM	64.0f	//�{�^���؂��艺

#define START_BUTTON_LEFT_EXP	4		//start���g��
#define START_BUTTON_RIGHT_EXP	8		//start�E�g��

#define END_BUTTOM_RIGHT_EXP	4		//end�E�g��

#define START_POS_TOP		 80		//�{�^���`��㒲��
#define START_POS_LEFT		150		//�{�^���`�捶����
#define START_POS_RIGHT		150		//�{�^���`��E����
#define START_POS_BOTTOM	160		//�{�^���`�扺����
#define END_POS_TOP			160		//�G���h�{�^���`��㒲��
#define END_POS_LEFT		150		//�G���h�{�^���`�捶����
#define END_POS_RIGHT		150		//�G���h�{�^���`��E����
#define END_POS_BOTTOM		240		//�G���h�{�^���`�扺����

//�C�j�V�����C�Y
void CObjGameTitle::Init()
{
	m_key_flag = false;
	lavel_select = LAVEL_TOP;
	lavel_button = true;
	lavel_button2 = true;
}

//�A�N�V����
void CObjGameTitle::Action()
{
	if (Input::GetVKey('S'))
	{
		if (lavel_button == true)
		{

			lavel_select++;

			lavel_button = false;

		}
	}
	else
		lavel_button = true;

	if (Input::GetVKey('W'))
	{
		if (lavel_button2 == true)
		{

			lavel_select--;

			lavel_button2 = false;

		}
	}
	else
		lavel_button2 = true;


	if (lavel_select > LAVEL_BOT_T)
		lavel_select = LAVEL_TOP;
	if (lavel_select < LAVEL_TOP)
		lavel_select = LAVEL_BOT_T;


	//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		//Audio::Start(2);//���ʉ�
		if (m_key_flag == true)
		{
			if (lavel_select == LAVEL_TOP)
			{
				m_key_flag = false;
				Scene::SetScene(new CSceneMain());

			}
			else if (lavel_select == LAVEL_BOT_T)
			{
				Scene::SetScene(nullptr);
			}
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjGameTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 1.0f,1.0f,1.0f,0.5f };


	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�w�i
	//�؂���ʒu�̐ݒ�
	src.m_top = START_CUT_TOP;
	src.m_left = START_CUT_LEFT;
	src.m_right = START_CUT_RIGHT;
	src.m_bottom = START_CUT_BOTTOM;

	//�w�i�̈ʒu��ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(0, &src, &dst, c, 0.0f);




	//�X�^�[�g�{�^��
	//�؂���ʒu�̐ݒ�
	src.m_top = START_BUTTON_CUT_TOP;
	src.m_left = START_BUTTON_CUT_LEFT * START_BUTTON_LEFT_EXP;
	src.m_right = START_BUTTON_CUT_RIGHT * START_BUTTON_RIGHT_EXP;
	src.m_bottom = START_BUTTON_CUT_BOTTOM;

	//�w�i�̈ʒu��ݒ肵�`��
	dst.m_top = (WINDOW_SIZE_H / 2) + START_POS_TOP;
	dst.m_left = (WINDOW_SIZE_W / 2) - START_POS_LEFT;
	dst.m_right = (WINDOW_SIZE_W / 2) + START_POS_RIGHT;
	dst.m_bottom = (WINDOW_SIZE_H / 2) + START_POS_BOTTOM;
	if (lavel_select == LAVEL_TOP)
		Draw::Draw(2, &src, &dst, c, 0.0f);
	else
		Draw::Draw(2, &src, &dst, b, 0.0f);

	//�Q�[���I���{�^��
	//�؂���ʒu�̐ݒ�
	src.m_top = END_BUTTON_CUT_TOP;
	src.m_left = END_BUTTON_CUT_LEFT;
	src.m_right = END_BUTTON_CUT_RIGHT * END_BUTTOM_RIGHT_EXP;
	src.m_bottom = END_BUTTON_CUT_BOTTOM;

	//�w�i�̈ʒu��ݒ肵�`��
	dst.m_top = (WINDOW_SIZE_H / 2) + END_POS_TOP;
	dst.m_left = (WINDOW_SIZE_W / 2) - END_POS_LEFT;
	dst.m_right = (WINDOW_SIZE_W / 2) + END_POS_RIGHT;
	dst.m_bottom = (WINDOW_SIZE_H / 2) + END_POS_BOTTOM;
	if (lavel_select == LAVEL_BOT_T)
		Draw::Draw(2, &src, &dst, c, 0.0f);
	else
		Draw::Draw(2, &src, &dst, b, 0.0f);


}