#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int x;
    cin >>x;
    if (x<5) cout <<fixed << setprecision(2) <<(2.5-x);
    else if (x<10) cout <<fixed << setprecision(2) <<(2-1.5*(x-3)*(x-3));
    else cout <<fixed << setprecision(2) <<(x/2-1.5);
    return 0;
}