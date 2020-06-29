//STG�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"	

//�R���X�g���N�^
CSceneGameTitle::CSceneGameTitle()
{

}

//�f�X�g���N�^
CSceneGameTitle::~CSceneGameTitle()
{

}

//�Q�[���X�^�[�g���������\�b�h
void CSceneGameTitle::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"");

	
	//�w�i�ǂݍ���
	Draw::LoadImage(L"image.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"�C�w�i.png", 0, TEX_SIZE_1024);
	Draw::LoadImage(L"splite6.png", 2, TEX_SIZE_512);

	//�^�C�g���I�u�W�F�N�g�쐬
	CObjGameTitle* obj = new CObjGameTitle(); //�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_GAME_TITLE, 10);//�^�C�g���I�u�W�F�N�g�o�^


	/*
	//BGM���y�ǂݍ���
	Audio::LoadAudio(0, L"", BACK_MUSIC);

	//SE
	Audio::LoadAudio(1, L"", EFFECT);
	Audio::LoadAudio(2, L"", EFFECT);

	//�{�����[��
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	Audio::Start(0);
	*/



}

//�Q�[���X�^�[�g���s�����\�b�h
void CSceneGameTitle::Scene()
{

}