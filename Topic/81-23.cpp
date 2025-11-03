#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float a, b, c;
    cout << "Enter a";
    cin >> a;
    c = a;
    for (; fabs(a - b) > 1e-5;)
    {
        b = a;
        a = 0.5 * (b + c / b);
    }
    cout << a;
}
