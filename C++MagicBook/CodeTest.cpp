//CodeTest.cpp
//それぞれのチャプターのプログラムを実行する場所
#include <stdio.h>
#include <stdlib.h>

//===== SAMPLE INCLUDE =====
#include "Chapter1-class/class.h"
#include "Chapter2-namespace/namespace.h"
#include "Chapter3-new_delete/new_delete.h"
#include "Chapter4-enum/enum.h"
#include "Chapter5-cast/cast.h"
#include "Chapter6-overload/overload.h"

void ClassTest();
void ClassTest2();
void NewDeleteTest();
void CastTest();
void OverloadTest();

int main(void)
{
	//----- CLASS -----
	printf("----- CLASS -----\n");
	ClassTest();
	printf("\n");
	printf("----- CLASSの継承についての挙動 -----\n");
	ClassTest2();
	printf("\n");

	//----- NEW / DELETE -----
	printf("----- NEW / DELETE -----\n");
	NewDeleteTest();
	printf("\n\n");

	//----- CAST -----
	printf("----- CAST -----\n");
	CastTest();
	printf("\n\n");

	//----- OVER LOAD -----
	printf("----- OVER LOAD -----\n");
	OverloadTest();
	printf("\n");

	printf("\n");
	return 0;
}

void ClassTest()
{
	POS a;
	POS b(20, 30);
	a.SetPos(10, 15);

	printf("a.X:%d a.Y:%d\nb.X:%d b.Y:%d\n", a.GetPosX(), a.GetPosY(), b.GetPosX(), b.GetPosY());
	return;
}

void ClassTest2()
{
	Child child;
	//派生クラスのコンストラクタだけでなく、基底クラスのコンストラクタも呼び出される
	//呼ばれる順番は、”基底クラスのコンストラクタ→派生クラスのコンストラクタ”である

	child.Hello();
	//派生クラスのインスタンスで、基底クラスの関数を使うことができる
	child.HelloWorld();
	//もちろん自クラスの関数も使用できる

	//return時に呼ばれるデストラクタは、派生クラス→基底クラスの順
	return;
}

void NewDeleteTest()
{
	NewDelete1();
}

void CastTest()
{
	StaticCastTest();
}

void OverloadTest()
{
	printf("関数のオーバーロード\n");
	UseFUNC();
	printf("\n演算子のオーバーロード\n");
	UseOverPos();
}