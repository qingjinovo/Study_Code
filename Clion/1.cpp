#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cout << "请输入A猪的体重" << endl;
    cin >> a;
    cout << "请输入B猪的体重" << endl;
    cin >> b;
    cout << "请输入C猪的体重" << endl;
    cin >> c;
    //先判断AB猪
    if (a>b) {
        if (a>c) cout << "Azhuzhong" << endl;
        else cout << "Czhuzhong" << endl;
    }
    else  {
        if (a>c) cout << "Azhuzhong" << endl;
        else cout << "Czhuzhong" << endl;

    }
    //如果A猪重在判断AC猪
    //如果B猪重判断BC猪
    return 0;
}