#include <iostream>
using namespace std;
int main()
{
    int a[5] = {8, 6, 5, 4, 1};
    for (int i = 0; i < 5 / 2; i++)
    {
        int tem = a[i];
        a[i] = a[4 - i];
        a[4 - i] = tem;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}