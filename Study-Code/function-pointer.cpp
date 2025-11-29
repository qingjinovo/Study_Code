#include <iostream>
using namespace std;
void swap01(int a, int b)
{
    int tem = a;
    a = b;
    b = tem;
    return;
}
void swap02(int *p, int *p1)
{
    int * tem=p;
    p=p1;
    p1=tem;
}
int main()
{
    int a = 1, b = 2, c = 3;
    swap01(a, b);
    swap02(&a, &b);
}