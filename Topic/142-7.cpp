#include <iostream>
using namespace std;
int main()
{
    int x, y;
    int a[5][5] = {{1, 2, 3, 4, 5},
                   {5, 6, 7, 8, 1},
                   {9, 3, 1, 2, 0},  // 第2行，第1列的3是这一行的最小值
                   {4, 5, 6, 7, 2},
                   {8, 9, 1, 3, 4}};
    for (int n = 0; n < 5; n++)//遍历每一行
    {
        for (int i = 0; i < 5; i++)//查找第n行的最大值列
        {
            if (a[n][i] < a[n][i + 1]) x = i+1;
        }
        for (int i = 0; i < 5; i++)//查找这一列的最小行
        {
            if (a[i][x] < a[i+1][x]) y=i;
        }
        if (n==y) cout<<a[n][x]<<endl;
    }
    return 0;
}