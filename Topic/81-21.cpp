#include <iostream> 
using namespace std;
int main ()
{
    float a,b,s,a1;
    a1=a=2;b=1;s=0;
    for (int i = 0; i < 20; i++)
    {
        s=(a/b)+s;
        a=a+b;
        b=a1;
    }
    cout <<s;
}