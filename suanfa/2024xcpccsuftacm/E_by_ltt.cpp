//这个大佬用的是vector数组
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);//好像是分离cin和什么的联系可以减少运行时间

    int n;
    cin >> n;
    vector<long long> pre(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }

    int m;
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r; // 题目保证 1<=l<=r<=n
        cout << pre[r] - pre[l - 1] << "\n";
    }
    return 0;
}