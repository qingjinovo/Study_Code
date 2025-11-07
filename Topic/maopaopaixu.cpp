// Ã°ÅİÅÅĞò
#include <iostream>
using namespace std;
int main()
{
    int array[9] = {5, 4, 8, 9, 6, 3, 7, 2, 1};
    for (int i = 0; i < 9; i++)
    {
        cout << array[i] << endl;
    }
    cout << "¿ªÊ¼Ã°Åİ£¬¹¾àà¹¾àà" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (array[x] > array[x + 1])
            {
                int tem = array[x];
                array[x] = array[x + 1];
                array[x + 1] = tem;
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        cout << array[i] << endl;
    }
    return 0;
}