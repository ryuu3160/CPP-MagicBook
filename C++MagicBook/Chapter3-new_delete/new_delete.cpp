//new_delete.cpp
#include "new_delete.h"
#include <stdlib.h>
#include <stdio.h>

//この章ではnewとdeleteについて説明する
//newとdeleteは、メモリの確保と解放を行う演算子である
//※new演算子、delete演算子と記述するのが正しいが、見やすくするため、以下ではnew,deleteと省略して記述する
//使用方法は以下のとおりである

void NewDelete1(void)
{
	//newは指定したデータ型の動的メモリを確保する
	//ポインタでメモリ番地を受け取る

	int* nNum1 = new int;//初期化なし
	int* nNum2 = new int(20);//初期化あり

	//newを使えば、int型のような組み込み型はもちろん、構造体・クラスといったデータ型の動的メモリを確保することができる

	//newの基本的な書き方は、'new データ型名;' 'new データ型名(初期値);'である

	*nNum1 = 10;

	//変数に格納されているデータと、確保したメモリのアドレスを表示
	printf("nNum1 : %d\nnNum1Address : %p\n", *nNum1,nNum1);
	printf("nNum2 : %d\nnNum2Address : %p\n", *nNum2, nNum2);

	//deleteは、newで確保した動的メモリを開放する
	delete nNum1;
	delete nNum2;

	//deleteの基本的な書き方は、'delete ポインタ変数名;'である

	//ちなみに、newで確保したメモリは、deleteでのみ解放できる
	//free関数では解放することができないため、要注意だ
	//逆もまたしかりで、mallocやcallocで確保したメモリをdeleteで解放することは出来ない
	//そのため、これらが混ざらないようにC++ではnew/deleteを使って、malloc/freeなどは極力使わないようにすること


	//new・deleteで配列を確保・解放する方法
	
	int* nArray = new int[5];//動的メモリ確保

	//newでの配列確保の基本的な書き方は、'new データ型名[要素数];'である
	//ちなみに、動的メモリ配列は任意の値で初期化することは出来ないが、0でなら初期化することができる
	//その書き方は、'new データ型名[要素数]();'である
	//この書き方をすると確保された領域が全て0で初期化される

	//配列への格納
	for (int i = 0; i < 5; i++)
	{
		nArray[i] = i;
	}
	//格納した値の出力
	for (int i = 0; i < 5; i++)
	{
		printf("nArray[%d] : %d  nArrayAddress : %p\n", i, nArray[i], &nArray[i]);
	}

	delete[] nArray;//動的メモリ配列の解放

	//deleteでの動的メモリ配列の解放の基本的な書き方は、'delete[] ポインタ変数名;'である


	//クラスオブジェクトに対するnew/deleteの使用方法
	//以下がnew_delete.hに書いてあるNewPosクラスを動的メモリに確保する書き方

	//オブジェクトの確保・解放
	NewPos* cNP = new NewPos;
	delete cNP;

	//オブジェクト配列の確保・解放
	NewPos* caNP = new NewPos[5];
	delete[] caNP;

	printf("\n");//見易さ向上のための改行

	//クラスオブジェクトを動的メモリに確保、解放する時、newとdeleteはコンストラクタとデストラクタを呼び出してくれる
	//mallocやcalloc、freeではコンストラクタとデストラクタを呼び出すことが出来ない
	//これがC++でnewとdeleteを使った方がいい理由である


	//クラス内での動的メモリ確保・解放
	DynamicPOS dPos;
	dPos.SetX(10);
	dPos.DisplayPos();
	return;
}

//クラスのメンバ変数を動的メモリで確保したい場合の書き方
//new_delete.hも同時に見ると分かりやすいと思われる
//下記にコンストラクタとデストラクタの記述方法を示す

//コンストラクタ
DynamicPOS::DynamicPOS()
{
	//コンストラクタ内でメモリの確保
	printf("DynamicPOSコンストラクタ、メモリ確保!\n");
	this->x = new int;//初期化なし
	this->y = new int(20);//初期化あり
}

//デストラクタ
DynamicPOS::~DynamicPOS()
{
	//デストラクタ内で必ずメモリの解放をする
	//これをやらないとメモリリークが発生してしまう
	printf("DynamicPOSデストラクタ、メモリ解放!\n");
	delete this->x;
	delete this->y;
}

//xに値を入れる関数
void DynamicPOS::SetX(int x)
{
	*this->x = x;
}

//値表示用の関数
void DynamicPOS::DisplayPos(void)
{
	printf("x : %d\nxAddress : %p\n", *this->x, this->x);
	printf("y : %d\nyAddress : %p\n", *this->y, this->y);
}

//下記はテスト用の貯め気にしなくてもよい
NewPos::NewPos()
{
	this->x = 0;
	this->y = 0;
	printf("コンストラクタ\n");
}
NewPos::~NewPos()
{
	printf("デストラクタ\n");
}