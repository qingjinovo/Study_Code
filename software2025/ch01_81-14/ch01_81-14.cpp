#include  <iostream>
using namespace std;
int main() {
    int a, b, c,d;
    cout<<"请输入4个数字"<<endl;
    cin>>a>>b>>c>>d;
    //比较第12和34个数
    if (a>b) {int x=a; a=b ;b=x;}
    if (c>d) { int x=c; c=d; d=x;}
    //比较13和24，确定最大最小值
    if (a>c) {int x=a ; a=c; c=x;}
    if (b>d) {int x=b; b=d; d=x;}
    //最后比较23得出最终顺序
    if (b>c) { int x=b; b=c; c=x;}
    cout<<a<<b<<c<<d<<endl;
    return 0;
}