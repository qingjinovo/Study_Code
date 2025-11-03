#include <iostream>
using namespace std;
int main()
{
    string name;
    float age,height;

    cout << "请输入您的姓名:" <<endl;
    cin >> name;
    cout << "请输入您的身高（CM）；" <<endl;
    cin >>height;
    cout << "请输入您的年龄；" << endl;
    cin >> age;
    //总和信息输出内容
    
    cout << "信息输入完成，您的信息如下；" << endl;
    cout << "姓名；" << name << endl;
    cout << "身高："  << height << "cm" <<endl;
    cout << "年龄；"  << age << endl;
    return 0;
}