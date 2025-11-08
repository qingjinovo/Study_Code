#include <iostream>
using namespace std;
int f(int x);
int main()
{
    int n;
    cout << "please enter n" << endl;
    cin >> n;
    cout << "anwser is " << f(n) << endl;
    return 0;
}
int f(int x)
{
    if (x==1) return 1;
    else return x*x+f(x-1);
}