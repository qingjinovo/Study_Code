#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(n%(m=1)==0) cout<<"Bob";
    else cout<<"Alice";
    return 0;
}