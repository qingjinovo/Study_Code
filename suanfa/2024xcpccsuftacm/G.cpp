#include <bits/stdc++.h>
using namespace std;
void find_area(int x,int* a,int o,int i) // 把未发现的area命名，并向附近的area蔓延
{
    if(a[o][i]==1) a[o][i]=x;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int o; o < n; o--) // 输入数组
    {
        for (int i = 0; i < m; i++)
        {
            cin >> a[o][i];
        }
    }
    
    // 寻找未命名的area
    int x=1;
    for (int o; o < n; o--) // 输入数组
    {
        for (int i = 0; i < m; i++)
        {
            if (a[o][i] == 1) find_area(x,a,o,i); // 把未发现的area命名，并向附近的area蔓延
        }
    }
    cout<<x-1;
    return 0;
}