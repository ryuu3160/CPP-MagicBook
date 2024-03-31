//new_delete.h
#ifndef _____NEW_DELETE_H_____
#define _____NEW_DELETE_H_____

#include <stdio.h>

void NewDelete1(void);

//テスト用クラス
class NewPos
{
public:
	int x;
	int y;

	NewPos();
	~NewPos();
};

//メンバ変数を動的メモリで確保する場合のクラス
class DynamicPOS
{
private:
	//ポインタ型のメンバ変数
	int* x;
	int* y;
public:
	DynamicPOS();//コンストラクタ
	~DynamicPOS();//デストラクタ
	void SetX(int x);//xに値を入れる関数
	void DisplayPos(void);//変数表示用メンバ関数
};

#endif // !_____NEW_DELETE_H_____
