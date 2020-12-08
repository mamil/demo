#include <memory>
#include <iostream>

class Empty {
public:
    int n_;
    Empty() = default;
    Empty (const Empty& a) {
        printf ("拷贝构造\n");
        this->n_ = a.n_;
    }

    Empty& operator= (const Empty& a) {
        printf ("赋值构造\n");
        this->n_ = a.n_;
    }
    Empty (int n) {
        printf ("address: %x\n", this);
        n_ = n;
    }
    ~Empty() {
        printf ("delete %x\n", this);
    }
};

int main()
{
    Empty a(1);
    Empty c = a;

    printf ("=============\n");

    Empty d;
    d = a;
}