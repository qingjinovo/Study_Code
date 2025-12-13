/*
编程语言C++14 (GCC 9) O2
代码长度588B
用时4ms
内存788.00KB */
#include <iostream>
using namespace std;
// 第一行输出2个空格，一个*
// 第二行输出1个空格，三个*
// 第三行输出5个*
int main()
{
    int x = 1;                  // x为*个数
    for (int i = 3; i > 0; i--) // i为行数
    {
        for (int n = 0; n < i - 1; n++)
            cout << " ";
        for (int n = 0; n < x; n++)
            cout << "*";
        x += 2;
        cout << endl;
    }
    x -= 2;
    for (int i = 1; i < 3; i++)
    {
        x -= 2;
        for (int n = 0; n < i; n++)
            cout << " ";
        for (int n = 0; n < x; n++)
            cout << "*";
        cout << endl;
    }
    return 0;
}