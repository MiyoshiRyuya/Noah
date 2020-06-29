#pragma once
//使用するヘッダーファイル

#include"GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameTitle.h"
#include"main.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//タイトルandメニュー関連-----------------------
#define LAVEL_TOP   0		//ラベルの一番上(スタート)

#define LAVEL_MID_M 1		//メニューラベルの真ん中()
#define LAVEL_BOT_M 2		//メニューラベルの一番下()

#define LAVEL_BOT_T 1		//タイトルラベルの一番下()

#define START_CUT_TOP		0.0f	//タイトル画像切り取り上
#define START_CUT_LEFT		0.0f	//タイトル画像切り取り左
#define START_CUT_RIGHT		1024.0f  //タイトル画像切り取り右
#define START_CUT_BOTTOM	512.0f	//タイトル画像切り取り下

#define START_BUTTON_CUT_TOP	0.0f	//ボタン切り取り上
#define START_BUTTON_CUT_LEFT	64.0f	//ボタン切り取り左
#define START_BUTTON_CUT_RIGHT	64.0f	//ボタン切り取り右
#define START_BUTTON_CUT_BOTTOM	64.0f	//ボタン切り取り下

#define END_BUTTON_CUT_TOP		0.0f	//ボタン切り取り上
#define END_BUTTON_CUT_LEFT		0.0f	//ボタン切り取り左
#define END_BUTTON_CUT_RIGHT	64.0f	//ボタン切り取り右
#define END_BUTTON_CUT_BOTTOM	64.0f	//ボタン切り取り下

#define START_BUTTON_LEFT_EXP	4		//start左拡大
#define START_BUTTON_RIGHT_EXP	8		//start右拡大

#define END_BUTTOM_RIGHT_EXP	4		//end右拡大

#define START_POS_TOP		 80		//ボタン描画上調整
#define START_POS_LEFT		150		//ボタン描画左調整
#define START_POS_RIGHT		150		//ボタン描画右調整
#define START_POS_BOTTOM	160		//ボタン描画下調整
#define END_POS_TOP			160		//エンドボタン描画上調整
#define END_POS_LEFT		150		//エンドボタン描画左調整
#define END_POS_RIGHT		150		//エンドボタン描画右調整
#define END_POS_BOTTOM		240		//エンドボタン描画下調整

//イニシャライズ
void CObjGameTitle::Init()
{
	m_key_flag = false;
	lavel_select = LAVEL_TOP;
	lavel_button = true;
	lavel_button2 = true;
}

//アクション
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


	//エンターキーを押してシーン：ゲームメインに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		//Audio::Start(2);//効果音
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

//ドロー
void CObjGameTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 1.0f,1.0f,1.0f,0.5f };


	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//背景
	//切り取り位置の設定
	src.m_top = START_CUT_TOP;
	src.m_left = START_CUT_LEFT;
	src.m_right = START_CUT_RIGHT;
	src.m_bottom = START_CUT_BOTTOM;

	//背景の位置を設定し描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(0, &src, &dst, c, 0.0f);




	//スタートボタン
	//切り取り位置の設定
	src.m_top = START_BUTTON_CUT_TOP;
	src.m_left = START_BUTTON_CUT_LEFT * START_BUTTON_LEFT_EXP;
	src.m_right = START_BUTTON_CUT_RIGHT * START_BUTTON_RIGHT_EXP;
	src.m_bottom = START_BUTTON_CUT_BOTTOM;

	//背景の位置を設定し描画
	dst.m_top = (WINDOW_SIZE_H / 2) + START_POS_TOP;
	dst.m_left = (WINDOW_SIZE_W / 2) - START_POS_LEFT;
	dst.m_right = (WINDOW_SIZE_W / 2) + START_POS_RIGHT;
	dst.m_bottom = (WINDOW_SIZE_H / 2) + START_POS_BOTTOM;
	if (lavel_select == LAVEL_TOP)
		Draw::Draw(2, &src, &dst, c, 0.0f);
	else
		Draw::Draw(2, &src, &dst, b, 0.0f);

	//ゲーム終了ボタン
	//切り取り位置の設定
	src.m_top = END_BUTTON_CUT_TOP;
	src.m_left = END_BUTTON_CUT_LEFT;
	src.m_right = END_BUTTON_CUT_RIGHT * END_BUTTOM_RIGHT_EXP;
	src.m_bottom = END_BUTTON_CUT_BOTTOM;

	//背景の位置を設定し描画
	dst.m_top = (WINDOW_SIZE_H / 2) + END_POS_TOP;
	dst.m_left = (WINDOW_SIZE_W / 2) - END_POS_LEFT;
	dst.m_right = (WINDOW_SIZE_W / 2) + END_POS_RIGHT;
	dst.m_bottom = (WINDOW_SIZE_H / 2) + END_POS_BOTTOM;
	if (lavel_select == LAVEL_BOT_T)
		Draw::Draw(2, &src, &dst, c, 0.0f);
	else
		Draw::Draw(2, &src, &dst, b, 0.0f);


}