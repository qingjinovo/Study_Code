#include <iostream>
using namespace std;
int main (){
    int a,b,c,n,x;
    x=0;
    cin>>n;
    cin>>a;
    cin>>b;
    cin>>c;
    for(;n>=c;x++)
    {
        if (n>=a) n-=a;
        else if (n>=b) n-=b;
        else if (n>=c) n-=c;
        cout <<n<<endl;
    }
    cout << x;
    return 0;
}