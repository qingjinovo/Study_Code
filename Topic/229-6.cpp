#include <iostream>
using namespace std;
class CFZ
{
public:
    void Show_CFZMJ()
    {
        cout << length * width * height<<endl;
    }
    void Set_CFZ()
    {
        cin>>length>>width>>height;
    }
private:
    int length;
    int width;
    int height;
};
int main()
{
    CFZ a, b, c;
    cout <<"please enter CFZ a,b,c's length,width and height"<<endl;
    a.Set_CFZ();
    b.Set_CFZ();
    c.Set_CFZ();
    cout <<"a的体积是"<<endl;
    a.Show_CFZMJ();
    cout <<"b的体积是"<<endl;
    b.Show_CFZMJ();
    cout <<"c的体积是"<<endl;
    c.Show_CFZMJ();
    return 0;
}