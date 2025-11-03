#include <iostream>
using namespace std;
int main()
{

	int scores[3][3] =
	{
		{100,100,100},
		{90,50,100},
		{60,70,80},
	};

	string names[3] = { "张三","李四","王五" };

	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += scores[i][j];
		}
		cout << names[i] << "同学总成绩为： " << sum << endl;
	}

system("pause");


/*     int array1[3] ={244,5,8};

    int array2[3];
    array2[0] =2;
    array2[1] =5;
    array2[2] =8;

    int array3[] ={2,5,8};


    cout << array1 <<endl;
    cout << array2 <<endl;
    cout << (int)&array3[0] <<endl; 
    cout << (int)&array3[1] <<endl; 
    cout << (int)&array3[2] <<endl;  */
    return 0;
}