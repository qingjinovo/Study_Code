#include <iostream>
using namespace std;
int main()
{
    // 求因子
    // 判断因子相加等于原数
    int a, i, x;//a为原数，i为因子，x为因子相加
    for (a = 1; a < 1001; a++)
    {
        i = 1;
        x = 0;
        for (; i <= a - 1; i++)
        {
            if (a % i == 0)
                x += i;
        }
        if (x == a)
            cout << a <<endl;
    }
    return 0;
}