//CodeTest.cpp
//それぞれのチャプターのプログラムを実行する場所
#include <stdio.h>
#include <stdlib.h>

//===== SAMPLE INCLUDE =====
#include "Chapter1-class/class.h"
#include "Chapter2-namespace/namespace.h"
#include "Chapter3-new_delete/new_delete.h"
#include "Chapter4-enum/enum.h"

void ClassTest();
void NewDeleteTest();

int main(void)
{
	//----- CLASS -----
	ClassTest();
	printf("\n");
	//----- NEW / DELETE -----
	printf("----- NEW / DELETE -----\n");
	NewDeleteTest();
	return 0;
}

void ClassTest()
{
	printf("----- CLASS -----\n");
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