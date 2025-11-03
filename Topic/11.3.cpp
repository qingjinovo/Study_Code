#include <iostream>
using namespace std;
int F(int x)
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
    int n, s;
    s = 0;
    cin >> n;
    for (; n > 0; n--)
    {
        s += F(n);
    }
    cout << s;
}