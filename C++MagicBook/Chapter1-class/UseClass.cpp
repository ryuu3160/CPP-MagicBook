//UseClass.cpp
#include "class.h"

int UseClass(void);
void UseClassInheritance();

//以下はクラスの基本的な使い方である
int UseClass(void)
{
	//----- インスタンスの作成(オブジェクトの生成) -----

	//オブジェクト生成時に自動的にコンストラクタが呼ばれる

	POS a;//デフォルトコンストラクタでのオブジェクト生成

	POS b(10, 10);//引数のあるコンストラクタでのオブジェクト生成


	//メンバの呼び出し方は構造体と大して変わらない
	a.GetPosX();//関数の呼び出し

	a.SetPos(5, 5);//引数のある関数の呼び出し

	return 0;
	//returnされた時に、デストラクタが自動で呼ばれる
}

//継承
void UseClassInheritance()
{
	//派生クラスのオブジェクトを作成
	Child child;
	
	child.Hello();//基底クラスにある関数を呼び出せる
	child.HelloWorld();//もちろん自クラスの関数も呼び出せる

	return;
}