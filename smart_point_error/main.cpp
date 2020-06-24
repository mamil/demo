#include <iostream>
#include <memory>

// std::shared_ptr 被提前释放：
void process1(std::shared_ptr<int> svp) {}
void example1()
{
    int *vp = new int(10);
    process1(std::shared_ptr<int>(vp));
    std::cout << *vp << std::endl; // pointer "vp" has already been released.
}

//使用栈对象初始化智能指针，造成悬挂指针：
auto process2()
{
    int v = 10;
    int *vp = &v;
    return std::shared_ptr<int>(vp); // 离开函数之后，v被销毁，指针指向的地址无效
}
void example2()
{
    std::cout << *process2() << std::endl; // dangling pointer.
}

// std::shared_ptr 造成的循环引用：
struct C
{
    ~C() { std::cerr << "destructor\n"; }
    std::shared_ptr<C> sp;
};
void example3()
{
    auto p = std::make_shared<C>(), q = std::make_shared<C>();
    p->sp = q;
    q->sp = p;
}

// 悬挂指针
struct P
{
    ~P() { std::cerr << "destructor\n"; }
    int n;
};
auto process5()
{
    P p;
    p.n = 10;
    P *vp = &p;
    return std::shared_ptr<P>(vp); // 离开函数之后，p被销毁，指针指向的地址无效。另外还会被析构两次。虽然值能打印出来，那不过是释放的地址对应的值没有被清零
}
void example5()
{
    std::cout << process5()->n << std::endl; // dangling pointer.
}

// 不当用法造成的潜在内存泄露：
bool complicatedCompute()
{ /* ... */
    return true;
} // potential memory leak;
auto process4(std::shared_ptr<int>, bool) {}
void example4()
{
    process4(std::shared_ptr<int>(new int(10)), complicatedCompute());
}

int main()
{
    example1();

    // example2();
    // example5();

    // example3();
    // example4();

    return 0;
}
