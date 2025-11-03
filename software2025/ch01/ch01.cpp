#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	float r, h;
	cout << "请输入圆半径r" << endl;
	cin >> r;
	cout << "请输入圆柱高h" << endl;
	cin >> h;
	cout << setiosflags(ios::fixed) << setprecision(2) << "圆周长为" << (2 * 3.14 * r) << endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << "圆面积为" << (3.14 * r * r) << endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << "圆球表面积为" << (4 * 3.14 * r * r) << endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << "圆球体积为" << (4 * 3.14 * r * r * r / 3) << endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << "圆柱体积为" << (3.14 * r * r * h) << endl;
	return 0;
}
