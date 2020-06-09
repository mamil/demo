#include <functional>
#include <iostream>

struct Foo {
    Foo(int num) : num_(num) { std::cout << "ctor Foo, num:" << num_ << "\n"; }
    ~Foo() { std::cout << "dtor Foo, num:" << num_ << "\n"; }
    Foo(const Foo& f) { *this = f; std::cout << "copy ctor Foo, num:" << num_ << "\n";}
    void print_add(int i) const { std::cout << num_ + i << '\n'; }
    int num_;
};

void print_num(int i) { std::cout << i << '\n'; }

struct PrintNum {
    void operator()(int i) const { std::cout << i << '\n'; }
};

int main() {
    // 存储自由函数
    std::function<void(int)> f_display = print_num;
    f_display(-9);
    // f_display = std::function<void(int)>{};
    // f_display(-8); //std::bad_function_call


    // 存储 lambda
    std::function<void()> f_display_42 = []() { print_num(42); };
    f_display_42();

    // 存储到 std::bind 调用的结果
    std::function<void()> f_display_43 = std::bind(print_num, 43);
    f_display_43();

    // 存储到成员函数的调用
    std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    const Foo foo(44);
    f_add_display(foo, 1);
    f_add_display(45, 1); // 构造然后调用,析构

    // 存储到数据成员访问器的调用
    std::function<int(Foo const&)> f_num = &Foo::num_;
    std::cout << "num_: " << f_num(foo) << '\n';

    // 存储到成员函数及对象的调用
    using std::placeholders::_1;
    std::function<void(int)> f_add_display2 = std::bind(&Foo::print_add, foo, _1); // foo对象会被拷贝一份
    f_add_display2(2);

    // 存储到成员函数和对象指针的调用
    std::function<void(int)> f_add_display3 = std::bind(&Foo::print_add, &foo, _1); // foo对象会被拷贝一份
    f_add_display3(3);

    // 存储到函数对象的调用
    std::function<void(int)> f_display_obj = PrintNum();
    f_display_obj(18);
}