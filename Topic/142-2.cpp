#include <iostream>
using namespace std;
int main()
{
    int a[] = {1, 5, 9, 8, 4, 7, 8, 6, 2, 3};
    for (int i = 0; i < 10; i++)
    {
        for (int n = 0; n < 9 - i; n++)
        {
            if (a[n] > a[n + 1])
            {
                int tem = a[n + 1];
                a[n + 1] = a[n];
                a[n] = tem;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout <<a[i]<<" ";
    }
    return 0;
}