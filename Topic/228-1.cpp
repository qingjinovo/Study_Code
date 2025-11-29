#include <iostream>
using namespace std;
class Time
{
public:
    void set_time();
    void show_time();

    int hour;
    int minute;
    int sec;
};
Time t;
int main(){
t.set_time();
t.show_time();
return 0;
}
void Time::set_time()//指明作用域时，作用域声明是在函数名前
{
    cin>>hour;
    cin>>minute;
    cin>>sec;
}
void Time::show_time(){
cout<<hour<<":"<<minute<<":"<<sec<<endl;
}