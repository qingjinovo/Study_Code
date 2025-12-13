/* 编程语言C++14 (GCC 9) O2
代码长度316B
用时20ms
内存956.00KB */
// 详细见B2025
#include <iostream>
using namespace std;
int main()
{
    char a;
    cin >> a;
    int x = 1;                  // x为*个数
    for (int i = 3; i > 0; i--) // i为行数
    {
        for (int n = 0; n < i - 1; n++)
            cout << ' ';
        for (int n = 0; n < x; n++)
            cout << a;
        x += 2;
        cout << endl;
    }
    return 0;
}