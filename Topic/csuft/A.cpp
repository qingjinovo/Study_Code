#include <iostream>
using namespace std;
int main()
{
    int n, m, x, i, i1;
    cin >> n;
    cin >> m;
    cin >> i;
    i1 = i;
    x = 1;
    for (; n > 1; n--)
    {
        cin >> i;
        if (i < i1)
        {
            x = 1;
            i1 = i;
        }
        else if (i == i1)
        {
            x++;
        }
    }
    if (x >= m)
    {
        cout << m;
    }
    else
    {
        cout << x;
    }
    return 0;
}