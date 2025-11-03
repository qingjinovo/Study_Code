#include <iostream>
using namespace std;
int main()
{
    int a, b, c, n, f;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter a: ";
    cin >> a;
    f=a;
    c=b=0;
    while (!(c==n))
    {
        b=b+a;
        a=a*10+f;
        c++;

    }
    cout << "The nth term is: " << b;
    return 0;
}