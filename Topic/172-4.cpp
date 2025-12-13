#include <iostream>
using namespace std;
void swaps_array(int *a, int n, int m)
{
    int tem[m];
    for (int i = 0; i < m; i++)
        tem[i] = a[n - m + i];
    for (int i = n - m - 1; i > -1; i--)
        a[i + m] = a[i];
    for (int i = 0; i < m; i++)
        a[i] = tem[i];
}
int main()
{
    int n, m;
    cout << "你要输入多少个数？交换多少个数？ " << endl;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    swaps_array(a, n, m);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}