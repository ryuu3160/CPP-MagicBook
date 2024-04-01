//enum.cpp
#include "enum.h"
#include <stdlib.h>
#include <stdio.h>

//C言語にあるenumとは別に、C++では"enum class"という機能が実装された
//※enum classはC++11以降に対応したコンパイラで利用可能
//下記にenum classの使用方法を示す

//既存のenumと違い、型定義をするときにtypedefが必要ない
enum class TEST
{
	hoge,
	boke,
	huge,
	bokeboke
};
//ちなみに、enum classの定義は、enum structとも書ける
enum struct TEST_S
{
	HOGE,
	BOKE,
	HUGE,
	BOKEBOKE
};

//定義の使い方
void UseEnum1()
{
	//スコープ解決演算子を使って、"型名::列挙子"と記述する
	TEST hogehoge = TEST::hoge;
	TEST_S HOGEHOGE = TEST_S::HOGE;
}

//enum classでは、管理するためのデータ型を指定できる
//下記がその例である

//既存のenumはint型をベースとした型だが、enum classでは管理するためのデータ型を自分で決めることができる
//型名の後ろに、": 整数型名"と記述することで、管理するデータ型を決めることができる
enum class GAME : short
{
	RPG,
	TRPG,
	FPS,
	TPS
};
//ここで注意してほしいのが、データ型の指定にはいくつかルールがあるという事だ
//1.指定できる型は整数型のみで、float型などの浮動小数点型は指定できない
//2.型の指定を省略した場合はint型になる
//3.型の指定で、unsignedを付けた場合、負数の値を設定できなくなる


//enum classでは列挙子以外の値を設定できない
//下記がその例である

enum class NUMBER
{
	ZERO,
	ONE,
	TWO,
	THREE
};

void UseEnum2()
{
	NUMBER num;
	num = NUMBER::ZERO;

	/*
	num = 1;//ビルドエラー、ONEの代わりに代入できない
	num = 5;//ビルドエラー、範囲外の整数値も代入できない
	*/
}


//enum classを使用する時の注意点
//enum classには様々な利点があるが、enumで出来ていた事が出来なくなる部分がある
//下記がその例である

enum class EXAMPLE
{
	c,
	cpp,
	java,
	python
};

void UseEnum3()
{
	//配列インデックスに利用できない
	int naNum[4] = {0};
	/*
	naNum[EXAMPLE::cpp] = 10;//ビルドエラー
	*/


	//加減算やインクリメント、デクリメントが出来ない
	EXAMPLE num = EXAMPLE::c;
	/*
	num += 1;//ビルドエラー、加減算出来ない
	num++;//ビルドエラー、インクリメント、デクリメントできない
	*/
}


//enum classは整数を扱うものの、int型などの整数型とは、代入や比較が出来ない
//だがしかし、キャストを使うことで、整数型に変換することはできる
//これにより、素の状態では出来なかった配列インデックスへの利用も可能になる
//キャストについての詳しいことはChapter5の説明を読んで欲しい