#include <iostream>
using namespace std;
//值传递，不改变实参
void swap01(int a, int b)
{
    int tem = a;
    a = b;
    b = tem;
    return;
}
//地址传递，可以改变实参
void swap02(int *p, int *p1)
{
    int tem=*p;
    *p=*p1;
    *p1=tem;
}
int main()
{
    int a = 1, b = 2, c = 3;
    swap01(a, b);
    swap02(&a, &b);
    return 0;
}