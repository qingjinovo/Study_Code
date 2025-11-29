#include <iostream>
using namespace std;
int main()
{
    int a[3][3] = {};
    for (int i = 0; i < 3; i++)
    {
        for (int n = 0; n < 3; n++)
        {            cin >> a[i][n];
        }
    }
    cout<<(a[0][0]+a[0][2]+a[1][1]+a[2][0]+a[2][2])<<endl;
}