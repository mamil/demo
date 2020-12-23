#include <iostream>
using namespace std;

class Empty
{
public:
	Empty()
	{
		cout << "Empty's constructor" << endl;
	}


	~Empty()
	{
		cout << "Empty's destructor" << endl;
	}

	void show()
	{
		cout << "num:" << num << endl;
	}

private:
	int num;
};

int main()
{
	char mem[100];
	mem[0] = 'E';
	mem[1] = '\0';
	mem[2] = '\0';
	mem[3] = '\0';
	cout << (void*)mem << endl;
	Empty* p = new (mem)Empty;
	cout << p << endl;
	p->show();
	p->~Empty(); // 不会自动调用析构
	getchar();
}