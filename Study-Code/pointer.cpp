#include <iostream>
using namespace std;

//指针

/* int main()
{
    int a = 1;
    int *p;
    p = (int *)0x61ff0111;
    cout << "a变量的地址是" << &a << endl;
    cout << "p指针指向a变量的地址是" << p << endl;
    // *p代表解引用
    cout << "a是" << *p << endl;
    *p = 100;
    cout << "经过指针修改内存后a是" << *p << endl;
    return 0;
} */

//空指针

/* int main()
{
    int * p;
    p = NULL;
    *p=100;
    cout <<p <<endl;
    cout <<*p;
    return 0;
} */
int main()
{
    //我的理解是p是是一个储存内存地址的变量
    //当const p时表示固定内存地址即固定指向
    //int * p指指向一个值
    //const int * p时表示const通过这个指针固定了这个值
    int a,b,c;
    a=b=c=1;
    //常量指针
    const int * p1 =&a ;
    p1 = (int *)0x454554;
    //*p1=100;
    
    //指针常量
    int * const p2 =&b ;
    //p2 = (int *)0x454554;
    *p2=100;
    //
    const int * const p3 =&c ;
    // p3 = (int *)0x454554;
    // *p3=100;
    return 0;
}