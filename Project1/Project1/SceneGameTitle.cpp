//STGデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"	

//コンストラクタ
CSceneGameTitle::CSceneGameTitle()
{

}

//デストラクタ
CSceneGameTitle::~CSceneGameTitle()
{

}

//ゲームスタート初期化メソッド
void CSceneGameTitle::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"");

	
	//背景読み込み
	Draw::LoadImage(L"image.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"海背景.png", 0, TEX_SIZE_1024);
	Draw::LoadImage(L"splite6.png", 2, TEX_SIZE_512);

	//タイトルオブジェクト作成
	CObjGameTitle* obj = new CObjGameTitle(); //タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_GAME_TITLE, 10);//タイトルオブジェクト登録


	/*
	//BGM音楽読み込み
	Audio::LoadAudio(0, L"", BACK_MUSIC);

	//SE
	Audio::LoadAudio(1, L"", EFFECT);
	Audio::LoadAudio(2, L"", EFFECT);

	//ボリューム
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(0);
	*/



}

//ゲームスタート実行中メソッド
void CSceneGameTitle::Scene()
{

}