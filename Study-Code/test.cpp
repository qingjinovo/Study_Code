#include <iostream>
using namespace std;
int a(int i)
{
    cout << "ijef" << endl;
    i++;
    return i;
}
int main()
{
    int i=0;
    cout <<i<<endl;   
    a(4);
    cout <<i;
    return 0;
}