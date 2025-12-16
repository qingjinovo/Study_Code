#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> vec;
    // vector <动态数组类型> vectorName
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(14);
    vec.push_back(5);
    // vectorName.push_back(Value)可以简单看成vector是一个类，vec就是一个对象
    // 而迭代器负责给对象的内置函数命名，让这个对象操作更方便
    vector<int>::iterator itBegin = vec.begin(); // 起始迭代器指向容器第一个元素
    vector<int>::iterator itEnd = vec.end();     // 结束迭代器指向最后一个元素的下一个位置
    //迭代器具有指针的性质
    //接下了输出动态数组的数
    cout<<*vec.begin();
    cout<<"你天才";
    return 0;
}