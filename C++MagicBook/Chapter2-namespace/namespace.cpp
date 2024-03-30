//namespace.cpp
#include "namespace.h"
//namespaceは本来ヘッダファイルで使用することがほとんどだと思うが、今回は例などを書くためcppで全て書いていく

//下記の2つの関数は名前が重複するため、コンパイルエラーになる

// FILE1.cpp
/*
void func(void)
{
    //処理
}
// FILE2.cpp
void func(void)
{
    //処理
}
*/

//下記のように書くことで名前が重複してもエラーにならない

//FILE1.cpp
namespace name1
{
    void func(int n);//プロトタイプ宣言はヘッダファイルに書くことが望ましい
    void func(int n)
    {
        // ...
    }
}
//FILE2.cpp
namespace name2
{
    void func(float f);//プロトタイプ宣言はヘッダファイルに書くことが望ましい
    void func(float f)
    {
        // ...
    }
}

//namespaceはネストすることが出来る
namespace a
{
    namespace b
    {
        namespace c
        {
            int d;
        }
    }
}
//namespaceのネストでは、下記のコードも上記と同じ意味になる(C++17以降)
//1年時に使用していたC++のバージョンは14なので、これは気にしなくてもよい
//それにこの書き方見づらいからね、一応知識だけ
/*
namespace aa::bb::cc{
    int dd;
}
*/

//namespace内に記述した関数の使い方
int UseNamespace(void)
{
    int n = 1;
    float f = 1.1f;

    name2::func(f);
    name1::func(n);

    //ネストされた名前空間の使い方
    a::b::c::d = 0;

    return 0;
}

//namespaceの別名定義
//namespaceは他のnamespaceとの衝突を防ぐため、十分にユニークな名前を付けなければならない
//そのため、namespaceの名前がとても長くなることがある
//namespace内の変数や関数を使うときにとても長い名前を毎回書くのは面倒なので、別名を定義することが出来る
//下記がその例である

//とても長い名前のnamespace
namespace SooooooooooooooooooLongerrrrrrrrrNaaaaaaaaaaaaaaame
{
    int x;
}

//ネストされた長い名前のnamespace
namespace SooooooooooLongName
{
    namespace SecondLongName
    {
        int y;
    }
}

void UseLongNamespace(void)
{
    //Soooo...にSLNという別名を定義
    namespace SLN = SooooooooooooooooooLongerrrrrrrrrNaaaaaaaaaaaaaaame;

    //SLNが使える！
    SLN::x = 0;

    //ネストされたnamespaceにSSLNという別名を定義
    namespace SSLN = SooooooooooLongName::SecondLongName;

    //SSLNが使える！
    SSLN::y = 0;

    //別名の別名を定義することも可能
    namespace S = SSLN;

    //Sが使える！
    S::y = 0;
}

//using宣言
//using宣言は宣言が書かれている宣言領域に、指定した名前を導入する
//これにより明示的に名前空間名と::演算子を使わなくても、その宣言領域で名前が使えるようになる
//using宣言を、名前空間のメンバーに使う場合、using宣言が書かれているスコープで::演算子による明示的なスコープの指定なしに、その名前を使うことができる
//下記がその例である
namespace N1
{
    int n;
}

void UsingDeclaration(void)
{
    // n = 0; //現時点でnは宣言されていないのでエラー

    using N1::n;
    n = 0;//N1::nと解釈される
    N1::n = 0;//明示的なスコープの指定
}

//usingディレクティブ
//usingディレクティブは、その記述以降のスコープにおける非修飾名前探索に、指定された名前空間内のメンバーを追加するための指示文である
//usingディレクティブを使うと、指定された名前空間内のメンバーを、::演算子を用いないで使用できる
//下記がその例である
namespace N2
{
    void func1();//プロトタイプ宣言
    int n;
    int y;
    int z;
    void func1() {/*処理*/}
}

void UsingDirectiv(void)
{
    using namespace N2;

    n = 0;//N2::nと解釈
    y = 0;//N2::yと解釈
    z = 0;//N2::zと解釈
    func1();//N2::func1と解釈
}

//クラスをnamespaceに入れる
//変数や関数のみではなく、クラスもnamespaceに入れることができる
//いくつかの書き方があるので、下記に示す
//※下記のコンストラクタの書き方は綺麗なものではないので、詳細はChapter1のclassを参照してください

//書き方その1
namespace c1
{
    class Class1
    {
    public:
        Class1() { nn = 0; }//コンストラクタ
        int nn;
        //色々
    };
}

//書き方その2(namespaceでのインデントをしていないだけ)
namespace c2
{
class Class2
{
public:
    Class2() { ny = 0; }//コンストラクタ
    int ny;
    //色々
};
}

//書き方その3
namespace c3
{
    class Class3;
}

class c3::Class3
{
public:
    Class3() { nz = 0; }//コンストラクタ
    int nz;
    //色々
};

//namespace内のクラスの使用方法
void UseNamespaceClass(void)
{
    c1::Class1 CC1;
    c2::Class2 CC2;
    c3::Class3 CC3;
    CC1.nn = 0;
    CC2.ny = 0;
    CC3.nz = 0;
}