#include <iostream>
using namespace std;
void bubble_sort(int *p, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int n = 0; n <= len - i - 1; n++)
        {
            if (p[n] > p[n + 1])
            {
                int tem = p[n];
                p[n] = p[n + 1];
                p[n + 1] = tem;
            }
        }
    }
    return;
}
void cout_array(int *array, int len)
{
    for(int i=0;i<len-1;i++)
    {
        cout << array[i] <<" ";
    }
    return;
}
int main()
{
    int array[] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
    int len = sizeof(array) / sizeof(array[0]);
    bubble_sort(array, len);
    cout_array(array,len);
    return 0;
}