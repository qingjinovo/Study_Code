#include <iostream>
using namespace std;
int main()
{
    int a=0,b=0,c=0,d=0,e=0;//a是数字，b是大写字母，c是小写,d是空格，e是其他
    char arr[]={};
    cin>>arr;
    cout <<"enter ~ end" <<endl;
    for(int i=0;sizeof(arr)/sizeof(arr[0]);i++)
    {
        if ((int)arr[i]<=57 && (int)arr[i]>=48) a++;
        else if ((int)arr[i]<=90 && (int)arr[i]>=65) b++;
        else if ((int)arr[i]<=122 && (int)arr[i]>=97) c++;
        else if ((int)arr[i]==32) d++;
        //else if ((int)arr[i]==176) break;
        else e++;
    }
    cout <<"数字有："<<a<<endl;
    cout <<"大写有："<<b<<endl;
    cout <<"小写有："<<c<<endl;
    cout <<"空格有："<<d<<endl;
    cout <<"其他有："<<e<<endl;
    return 0;
}