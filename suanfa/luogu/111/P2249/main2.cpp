// fix main1.cpp is false
#include <iostream>
using namespace std;
int main()
{
    int n, m, x, sign = 0;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        bool num = true;
        cin >> x;
        for (; sign < n; sign++)
        {
            if (x == a[sign])
            {
                cout << sign + 1 << " ";
                num = false;
                break;
            };
        }
        if (num)
            cout << "-1 ";
    }
    return 0;
}