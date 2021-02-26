#include<iostream>
using namespace std;
class Point
{
private:
    int _x;
    int _y;
public:
    Point(int x = 0, int y = 0) { _x = x; _y = y; }
    Point operator ++();//前置型
    Point operator ++(int);//后置型
    Point operator --();//前置型
    Point operator --(int);//后置型
    void Display();
    void autoDisplay();
    Point pp() { _x++; _y++; this->autoDisplay(); return *this; }
    Point mm() { _x--; _y--; return *this; }
    ~Point(){}
};
Point Point::operator ++() //前置型自增
{
    return pp();
}
Point Point::operator ++(int)//后置型自增
{
    Point p = *this;
    pp();
    return p;
}
Point Point::operator --()//前置型自减
{
    return mm();
}
Point Point::operator --(int)//后置型自减
{
    Point p = *this;
    mm();
    return p;
}
void Point::Display()
{
    cout << "( " << _x << " , " << _y << " )" << endl;
}

void Point::autoDisplay()
{
    cout << "auto ( " << _x << " , " << _y << " )" << endl;
}

void inFuncTest(Point p)
{
    std::cout << "in:" << std::endl;
    p.Display();
}

int main()
{
    Point a(1, 2);
    Point b;
    // b = ++a;
    // a.Display();
    // b.Display();
    b = a++; // auto (2,3)
    // a.Display();
    // b.Display();
    // b = --a;
    // a.Display();
    // b.Display();
    // b = a--;
    // a.Display();
    // b.Display();

// ( 2 , 3 )
// ( 2 , 3 )

// ( 3 , 4 )
// ( 2 , 3 )

// ( 2 , 3 )
// ( 2 , 3 )

// ( 1 , 2 )
// ( 2 , 3 )

// 结果分析
// 1.第一步，前置自增运算，先自增，再赋值给b。操作结束后a为（2，3），b为（2，3）。
// 2.第二步，后置自增运算，先赋值给b，后自增。操作结束后a为（3，4），b为（2，3）。
// 3.第三步，前置自减运算，先自减，再赋值给b。操作结束后a为（2，3），b为（2，3）。
// 4.第四步，后置自减运算，先赋值给b，后自减，操作结束后a为（1，2），b为（2，3）。

    std::cout << "in Func Test##" << std::endl;
    inFuncTest(a++);
    std::cout << "out" << std::endl;
    a.Display();
// auto ( 3 , 4 ) // inFuncTest里面的a++被执行
// in:
// ( 2 , 3 ) // 函数被执行
// out
// ( 3 , 4 )
}
