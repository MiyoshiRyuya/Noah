#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "SceneMain.h"
#include "GameHead.h"

#include "GameL/DrawTexture.h"
#include "GameL/SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"	

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{
	//外部グラフィックファイルの読み込み０番に登録(512×512ピクセル)
	Draw::LoadImage(L"image.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"海背景.png", 0, TEX_SIZE_1024);

	//背景
	CObjStage* objback = new CObjStage();	//作成
	Objs::InsertObj(objback, OBJ_STAGE, 0);	//マネージャーに登録

	//主人公オブジェ作成
	CObjNoah* obj = new CObjNoah();	//作成
	Objs::InsertObj(obj, OBJ_NOAH, 1);	//マネージャーに登録


}

//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{

}