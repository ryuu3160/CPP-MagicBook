//CodeTest.cpp
//それぞれのチャプターのプログラムを実行する場所
#include <stdio.h>
#include <stdlib.h>

//===== SAMPLE INCLUDE =====
#include "Chapter1-class/class.h"
#include "Chapter2-namespace/namespace.h"

int main(void)
{
	//----- CLASS -----
	POS a;
	POS b(20, 30);
	a.SetPos(10, 15);

	printf("a.X:%d a.Y:%d\nb.X:%d b.Y:%d\n", a.GetPosX(), a.GetPosY(), b.GetPosX(), b.GetPosY());

	return 0;
}