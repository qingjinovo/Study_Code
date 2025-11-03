#include <iostream>
using namespace std;
int main()
{
	
	int a,b, i,c,d,f;
	f = i = 0;
	cout << "请输入一个不多于5位的正整数" << endl;
	cin >> a;
	c = b = a;

	while (!(b == 0))
	{
		b = b / 10;
		i++;
	}
	cout << "该数为" << i << "位数" << endl;


	//cout << (a / d) << endl;
	//cout << (bool(!d == 0));
	for ( i = 0; i < 5; i++)
	{
		char w = a;
		cout << w << endl;
	}

	// 从低位到高位顺序输出每一位数字
	c = a; // 重新初始化c为原数字
	while (!(c == 0))
	{
		cout << (c % 10) << endl;
		c = c / 10;
	}
	return 0;
}