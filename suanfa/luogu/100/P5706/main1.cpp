/* 
编程语言C++14 (GCC 9) O2
代码长度189B
用时20ms
内存852.00KB */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float ml, one_ml;
    int n, cup;
    cin>>ml>>n;
    cout<<setprecision(3)<<fixed<<ml/n<<endl;
    cout<<2*n;
}