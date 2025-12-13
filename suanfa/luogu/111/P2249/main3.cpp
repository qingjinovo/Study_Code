// 自己写的二分法（还没看教程，后面可能会补一个完全版）
// 1.数据都是从大到小排序的（一开始想到了二分，但是没看到从大到小，后面就忘了）
// 我们就可以让x与a[n/2]比较    x是需要查询的数 a[]是输入的数组
// if x>a[n/2] 就判断x和a[n]的大小然后在判断n+n/2的二分比较，反之亦然
// 所以我们可以用一个循环来二分，循环停止的条件是两点=x，那输出的内容就是左端点的下标了
// ps 其实我感觉还可以用main2的方法去减小二分次数
// end 思考太久了，脑子坏了
#include <iostream>
using namespace std;
int main()
{
    int m, n, l, r, x, mid;
    bool bool_x;
    // l,r,mid二分法中 左右中
    //  输入n,m，和a[]数组
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // for循环找x
    for (int i = 0; i < m; i++)
    {
        bool_x = true;
        l = 0;
        r = n - 1;
        mid = (l + r) / 2;
        cin >> x;
        // 二分确定范围
        while (a[mid] != x && l!=r)
        {
            if (x > a[mid])
                l = mid + 1;
            else
                r = mid - 1;
            mid = (l + r) / 2;
        }
        for (; l < r; l++)
        {
            if (x == a[l])
            {
                cout << l + 1 << ' ';
                bool_x = false;
                break;
            }
        }
        if (bool_x)
            cout << "-1 ";
    }
    return 0;
}