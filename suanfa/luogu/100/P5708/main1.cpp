#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    float a,b,c,p;
    cin>>a>>b>>c;
    p=0.5*(a+b+c);
    cout<<setprecision(1)<<fixed<<round(sqrt(p*(p-a)*(p-b)*(p-c)));
    return 0;
}