//cast.cpp
#include "cast.h"
#include <stdlib.h>
#include <stdio.h>

//static_castについて
//"static_cast"とは、型変換を明示的に行うためのキャスト
//必要があれば値を変える
//下記が使い方である

void StaticCastTest()
{
	float fNum = 5.56f;
	int nNum;

	//使用例
	//"static_cast<変換する型名>(変換したい値);"と記述する
	nNum = static_cast<int>(fNum);
	//変換する型名には、自分で作った型も入れることが可能
	typedef int ImINTEGER;
	ImINTEGER inNum;
	inNum = static_cast<ImINTEGER>(fNum);

	//結果を表示
	printf("fNum : %f\nnNum : %d\ninNum : %d\n", fNum, nNum,inNum);


	//static_castでは、列挙型と整数型の変換などの、暗黙的に変換されない型変換も行うことが可能
	//これにより、enum classを配列インデックスなどに利用することができる
	//下記がその例である

	enum class CAST
	{
		A,//0
		B,//1
		C,//2
		D,//3
		E,//4
		F,//5
		G,//6
		H,//7
		I,//8
		J,//9
	};

	CAST cast1 = static_cast<CAST>(0);//CAST cast1 = CAST::A;と同じ意味になる
	int cast2 = static_cast<int>(CAST::B);//int cast2 = 1;と同じ意味になる

	int cast3[10] = { 0 };
	cast3[static_cast<int>(CAST::A)] = 10;//CAST::A(入っている値は0)を整数にキャストしてあげれば、配列インデックスとして利用できる

	//値の表示
	printf("cast1 : %d\ncast2 : %d\ncast3 : ", cast1, cast2);
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", cast3[i]);
	}
}