#include <iostream>
using namespace std;
int FACTORIAL(int x)
{
    int result = 1;
    for (; x != 0; x--)
    {
        result = result * x;
    }
    return result;
}
int main()
{
    cout << FACTORIAL(5) << endl;
    int i, x;
    x = 1;
    for (i = 20; i > 0; i--)
    {
        x = x + FACTORIAL(i);
    };
    cout << x << endl;

    return 0;
}