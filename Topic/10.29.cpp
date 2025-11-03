#include <iostream>
using namespace std;
int add (int x)
{
    int s=0;
    for (x; x>0; x--)
    {
        s=s+x;
    }
    return s;
}
int numb(int k)
{
    int i=1;
    for (k; add(i)<=k;i++) {}
    return (i-1);
}
int mult (int x)
{
    int s=0;
    for (s; x>0; x--)
    {
        s=s+x*x;
    }
    return s;
}
int main()
{
    int k;
    cout << "请输入天数k" <<endl;
    cin >> k;
    cout << "骑士赚了" << (mult(numb(k))+(k-add(numb(k)))*(numb(k)+1)) << "个金币";
    return 0;
}