#include <iostream>
using namespace std;
int main()
{
    int x,a=0;
    cout << "please enter x" << endl;
    cin >> x;
    for (int i = 1; i <= x; i++)
    {
        if (x%i==0) a+=i;
    }
    if (a==(x+1)) cout << x << "是素数" << endl;
    else cout << x << "不是素数" << endl;
    return 0;
}