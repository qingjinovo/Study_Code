/* 
unaccept
编程语言C++14 (GCC 9) O2
代码长度497B
用时5.54s
内存4.24MB */
//力大砖飞
#include <iostream>
using namespace std;
int main()
{
    int n, m, x, num;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    
    for (int i = 0; i < m; i++)
    {
        num = 0;
        cin >> x;
        for (int b = 0; b < n; b++)
        {
            if (x == a[b])
            {
                cout << b+1 << " ";
                num++;
                break;
            };
        }
        if(num == 0) cout << "-1";
    }
    return 0;
}