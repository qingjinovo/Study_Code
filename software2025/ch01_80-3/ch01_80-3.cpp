#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float f,c;
	cout << "请输入华氏温度" << endl;
	cin >> f;
	c = ((f - 32) * 5 / 9);
	cout << fixed << setprecision(2) << "该摄氏温度为" << c << endl;



}