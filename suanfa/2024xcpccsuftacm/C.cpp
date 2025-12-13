#include <bits/stdc++.h>
using namespace std;
long long pow1(long a, long b)
{
    if(b==0) return 1;
    else return(a*pow1(a,b-1));
}
int main()
{
    long long a, b, m;
    cin >> a >> b >> m;
    long long result = pow1(a, b);
    result=result%m;
    cout << result;
    return 0;
}