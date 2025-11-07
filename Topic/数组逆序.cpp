#include <iostream>
using namespace std;
int main()
{
    int n, x; // n是数组元素个数，x为换位的中间变量
    int array[5] = {1, 2, 3, 4, 5};
    n = sizeof(array) / sizeof(array[0]);
    for (int i = n; i > (n/2); i--)
    {
        x = array[n - i];
        array[n - i] = array[i-1];
        array[i-1] = x;
    }
    for (int i=0; i < n; i++)
    {
        cout << array[i] <<endl;
    }
    return 0;
}