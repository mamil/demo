#include <memory>
#include <iostream>

class Empty {
public:
    Empty (const Empty& a) {
        printf ("拷贝构造\n");
        printf ("address: %x\n", this);
    }
    Empty& operator= (const Empty& a) {
        printf ("赋值构造\n");
        printf ("address: %x\n", this);
    }
    Empty () {
        printf ("address: %x\n", this);
    }
    ~Empty() {
        printf ("delete %x\n", this);
    }
};

int main()
{
    Empty a;
    Empty c = a; // 拷贝构造

    printf ("=============\n");

    Empty d;
    d = a; // 赋值构造
}