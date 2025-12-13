#include <iostream>
using namespace std;
void cin_array(int *a)
{
    for (int i = 0; i < 10; i++)
        cin >> a[i];
}
void swap_array(int *a)
{
    for (int i = 0; i < 9; i++)
    {
        if (a[i] > a[i + 1])
        {
            int tem = a[i];
            a[i] = a[i + 1];
            a[i + 1] = tem;
        }
        if (a[9 - i] < a[8 - i])
        {
            int tem = a[9 - i];
            a[9 - i] = a[8 - i];
            a[8 - i] = tem;
        }
    }
}
void cout_array(int *a)
{
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
}

int main()
{
    int a[10];
    cin_array(a);
    swap_array(a);
    cout_array(a);
    return 0;
}