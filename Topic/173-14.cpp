#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n / 2; i++)
    {
        int tem = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = tem;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}