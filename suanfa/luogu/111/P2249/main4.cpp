#include <iostream>
using namespace std;
int main()
{
    int m, n, l, x, r, mid;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    l = -1;
    r = n;
    for (int i; i < m; i++)
    {
        cin >> x;
        while (r - l > 1)
        {
            mid = l + (l - r) / 2;
            if (a[l] >= x)
                r = mid;
            else
                l = mid;
        }
        if (l == -1 || r == n)
            cout << left << ' ';
        else
            cout << "-1 ";
    }
    return 0;
}