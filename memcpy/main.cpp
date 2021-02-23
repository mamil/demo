#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

void *mymemcpy(void *dest, const void *src, size_t n)
{
    assert(dest);
    assert(src);
	void *ret = dest;

    src = (char *)src + n - 1; // 这里-1是因为src已经算一个了
    dest = (char *)dest + n - 1;
    while (n--)
    {
        *(char *)dest = *(char *)src;
        dest = (char *)dest - 1;
        src = (char *)src - 1;
    }

	return ret;
}

int main()
{
	char src[]="123456789";
	char des[50];
    memcpy(des, src, strlen(src)+1);
	cout << "  memcpy   des:" << des << endl; // 123456789

	char mysrc[]="123456789";
	char mydes[50];
    mymemcpy(mydes, mysrc, strlen(mysrc)+1);
	cout << "mymemcpy mydes:" << mydes << endl; // 123456789

    char *des2 = src+3;
    memcpy(des2, src, strlen(src)+1);
    cout<< "  memcpy   src:" << src << endl; // 123123456789
	cout<< "  memcpy   des2:" << des2 << endl; // 123456789

    char *mydes2 = mysrc+3;
    mymemcpy(mydes2, mysrc, strlen(mysrc)+1);
    cout<< "mymemcpy mysrc:" << mysrc << endl; // 123123456789
	cout<< "mymemcpy mydes2:" << mydes2 << endl; // 123456789

    int ma=10;
    int mb;
    mymemcpy(&mb, &ma, sizeof(ma));
    cout<<mb<<endl;

    return 0;
}