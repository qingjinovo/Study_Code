//666我发现自己原来这么聪明；每次比赛题目都能看错
#include <bits/stdc++.h>
using namespace std;
int ef(int num, int *a, int n)
{
    int l = -1, r = n;
    while (r-l>1)
    {
        int mid = (l + r) / 2;
        if (a[mid]>=num)
        {
            r = mid;
        }
        else
            l = mid;
    }
    return r;
}
int main()
{
    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int l, r,result=0;
        cin >> l >> r;
        l = ef(l, a, n);
        r = ef(r, a, n);
        for(;l<=r;l++) result+=a[l];
        cout<<result<<endl;
    }
    return 0;
}