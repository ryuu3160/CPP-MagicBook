//overload.h
#ifndef _____OVERLOAD_H_____
#define _____OVERLOAD_H_____

void FUNC(int num);
void FUNC(float num);
void FUNC(int num1, float num2);
void UseFUNC();
void Use_sPos();
void UseOverPos();

//関数のオーバーロードの例
class OverPos
{
public:
	int x;
	int y;

	OverPos();
	void SetPos(int x,int y);
	OverPos operator+(OverPos rhs);//演算子のオーバーロードの宣言
};

#endif // !_____OVERLOAD_H_____
