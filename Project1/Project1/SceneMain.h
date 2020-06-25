#pragma once
#include "GameL/SceneManager.h"

using namespace GameL;

class CSceneMain :public CScene
{
public:
	CSceneMain();
	~CSceneMain();
	void InitScene();	//メイン初期化メソッド
	void Scene();		//メイン実行中メソッド
private:

};