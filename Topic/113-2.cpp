#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b, c; // a*pow(x,2)+b*x+c=0
    cout << "please enter a,b,c" << endl;
    cin >> a >> b >> c;
    int delta = (b * b - 4*a*c);
    void root1(int a, int b, int c);
    void root2(int a, int b);
    void root3();
    if (delta > 0)
        root1(a, b, c);
    else if (delta == 0)
        root2(a, b);
    else if (delta < 0)
        root3();
    return 0;
}
void root1(int a, int b, int c) // f(x)>0
{
    int x1=((-b+sqrt(delta))/(2*a));
    int x2=((-b-sqrt(delta))/(2*a));
    cout << x1 << "  " <<x2 <<endl;
    return;
}
void root2(int a, int b) // f(x)=0
{
    int x=((-b)/(2*a));
    cout << x <<endl;
    return;
}
void root3() // f(x)<0
{
    cout << "null" <<endl;
    return;
}
