#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "SceneMain.h"
#include "GameHead.h"

#include "GameL/DrawTexture.h"
#include "GameL/SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"	

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{
	//�O���O���t�B�b�N�t�@�C���̓ǂݍ��݂O�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"image.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"�C�w�i.png", 0, TEX_SIZE_1024);

	//�w�i
	CObjStage* objback = new CObjStage();	//�쐬
	Objs::InsertObj(objback, OBJ_STAGE, 0);	//�}�l�[�W���[�ɓo�^

	//��l���I�u�W�F�쐬
	CObjNoah* obj = new CObjNoah();	//�쐬
	Objs::InsertObj(obj, OBJ_NOAH, 1);	//�}�l�[�W���[�ɓo�^


}

//�Q�[�����C�����s�����\�b�h
void CSceneMain::Scene()
{

}