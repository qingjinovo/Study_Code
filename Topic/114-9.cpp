#include <iostream>
using namespace std;
void move(string one, string two, string three, int n)
{
    if (n == 1)
        cout << one << "=>" << three << endl;
    else
    {
        move(one, three, two, n - 1);
        cout << one << "=>" << three << endl;
        move(two, one, three, n - 1);
    }
}
int main()
{
    int n;
    cin >> n;
    move("A", "B", "C", n);
    return 0;
}