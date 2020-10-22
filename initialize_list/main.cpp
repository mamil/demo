#include <iostream>
using namespace std;
class Demo
{
private:
    int m_a;
    int m_b;
    const int m_c;

public:
    Demo(int b, int c);
    void show();
};
Demo::Demo(int b, int c) : m_b(b), m_a(m_b), m_c(c) {}
void Demo::show() { cout << m_a << ", " << m_b << ", " << m_c << endl; }

int main()
{
    Demo obj(100, 200);
    obj.show(); // 32766, 100, 200
    /*
        成员变量的初始化顺序与初始化列表中列出的变量的顺序无关，它只与成员变量在类中声明的顺序有关。

        在初始化列表中，我们将 m_b 放在了 m_a 的前面，看起来是先给 m_b 赋值，再给 m_a 赋值
        其实不然！成员变量的赋值顺序由它们在类中的声明顺序决定，
        在 Demo 类中，我们先声明的 m_a，再声明的 m_b

        给 m_a 赋值时，m_b 还未被初始化，它的值是不确定的，所以输出的 m_a 的值是一个奇怪的数字
        给 m_a 赋值完成后才给 m_b 赋值，此时 m_b 的值才是 100。
    */
    return 0;
}