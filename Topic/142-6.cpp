#include <iostream>
using namespace std;
int main()
{
    int a[1000] = {1};
    for (int i = 0; i < 10; i++)
    {
        a[i] = 1;
        for (int n = i - 1; n > 0; n--)
        {
            a[n] += a[n - 1];
        }
        for (int n = 0; n < i + 1; n++)
        {
            cout << a[n] << " ";
        }
        cout << endl;
    }
    return 0;
}
