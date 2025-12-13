#include <iostream>
using namespace std;
int main()
{
    float x, result = 0;
    int n;
    cin >> x;
    x *= 10;
    for (int i = 0; i < 4; i++)
    {
        n = (int)x % 10;
        result = result * 10 + n * 0.001;
        x /= 10;
    }
    cout <<result;
    return 0;
}