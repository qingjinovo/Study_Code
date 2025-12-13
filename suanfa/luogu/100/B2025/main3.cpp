/* 
编程语言C++14 (GCC 9) O2
代码长度462B
用时4ms
内存788.00KB */
#include <iostream>
using namespace std;
// 这为main2的修改版
//  x为*个数,i为空格数
// 定义bool_x，bool_i，来确定x i是否超过某一值
// 根据bool元素确定x i该加还是减
int main()
{

    int x = 1, i = 2;
    bool bool_x = true, bool_i = true;
    while (x > 0)
    {
        for (int n = 0; n < i; n++)
            cout << " ";
        for (int n = 0; n < x; n++)
            cout << "*";
        cout << endl;
        bool_x ? x += 2 : x -= 2;
        bool_i ? i-- : i++;
        if (x > 3)
            bool_x = false;
        if (i == 0)
            bool_i = false;
    }
    return 0;
}