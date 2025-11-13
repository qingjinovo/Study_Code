#include <iostream>
using namespace std;
// 定义一个圆的类
class round
{
public:
    const double pi = 3.14;
    double ZC(int r)
    {
        return 2 * pi * r;
    }
    double MJ(int r)
    {
        return pi * r * r;
    }
};
int main()
{
    int r;
    cin >> r;
    round ro;
    cout <<"ZC is " << ro.ZC(r) <<endl;
    cout <<"ZC is " << ro.MJ(r) <<endl;
    return 0;

}
