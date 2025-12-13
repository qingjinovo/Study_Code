//精度缺失
#include <iostream>
using namespace std;
int main()
{
    int n;
    double x, result=0;
    cin >> x;
    x /= 100.0;
    for (int i = 0; i < 4; i++)
    {
        n = (int)x % 10;
        result=0.1*result+n;
        x=(x-n)*10.0;
    }
    cout<<result;
    return 0;
}