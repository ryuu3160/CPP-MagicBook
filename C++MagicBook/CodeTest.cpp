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

void ClassTest();
void NewDeleteTest();
void CastTest();

int main(void)
{
	//----- CLASS -----
	printf("----- CLASS -----\n");
	ClassTest();
	printf("\n");
	//----- NEW / DELETE -----
	printf("----- NEW / DELETE -----\n");
	NewDeleteTest();
	printf("\n");
	//----- CAST -----
	printf("----- CAST -----\n");
	CastTest();

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

void NewDeleteTest()
{
	NewDelete1();
}

void CastTest()
{
	StaticCastTest();
}