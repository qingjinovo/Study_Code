#include <iostream>
using namespace std;
int main()
{
    int n;
    n = 1;
    for (int i = 1; i < 4; i++)
    {
        for (int a = 0; a < n; a++)
        {
            cout << "* ";
        }
        cout << endl;
        n += 2;
    }
    n = 7;
    for (int i = 0; i < 4; i++)
    {
        for (int a = 0; a < n; a++)
        {
            cout << "* ";
        }
        cout << endl;
        n -= 2;
    }
    return 0;
}
