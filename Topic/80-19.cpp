#include <iostream>
using namespace std;
int main()
{
    int a, b, c, x;
    int t(int x);
    for (a = 1; a < 10; a++)
    {
        for (b = 0; b < 10; b++)
        {
            for (c = 0; c < 10; c++)
            {
                x = t(a) + t(b) + t(c);
                // cout << x <<endl;
                if (x > 100 && x < 1000 && x == (a * 100 + b * 10 + c))
                    cout << x << endl;
            }
        }
    }
    return 0;
}
// third
int t(int x)
{
    x = x * x * x;
    return x;
}