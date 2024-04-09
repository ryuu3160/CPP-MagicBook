//class.cpp
#include "class.h"
#include <stdlib.h>
#include <stdio.h>

//メンバ関数の定義は全て、"クラス名::関数名(引数)"となる

//コンストラクタの定義
POS::POS()
{
	//thisポインタは自身のメンバを指定している
	this->x = 0;
	this->y = 0;
	printf("デフォルトコンストラクタ\n");//コンストラクタが呼ばれる場所が分かるようにするための措置
}

//引数ありコンストラクタの定義
POS::POS(int x, int y)
{
	//thisポインタを使用することで変数名と引数名が同じでも大丈夫
	//このthisポインタは省略してもOK(省略する場合は、引数名を変える必要がある)
	this->x = x;
	this->y = y;
	printf("引数ありコンストラクタ\n");//コンストラクタが呼ばれる場所が分かるようにするための措置
}

//デストラクタの定義
POS::~POS()
{
	//今のコードでは何も書く必要がない
	printf("デストラクタ\n");//デストラクタが呼ばれる場所が分かるようにするための措置
}

//メンバ関数の定義
int POS::GetPosX(void) const
{
	return this->x;
}

int POS::GetPosY(void) const
{
	return this->y;
}

void POS::SetPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

//----- 継承について -----

//基底クラスのコンストラクタ
Base::Base()
{
	printf("Baceコンストラクタ\n");
}
//基底クラスのデストラクタ
Base::~Base()
{
	printf("Baceデストラクタ\n");
}
//基底クラスの関数
void Base::Hello()
{
	printf("Bace:Hello\n");
}

//派生クラスのコンストラクタ
Child::Child()
{
	printf("Childコンストラクタ\n");
}
//派生クラスのデストラクタ
Child::~Child()
{
	printf("Childデストラクタ\n");
}
//派生クラスの関数
void Child::HelloWorld()
{
	printf("Child:HelloWorld\n");
}