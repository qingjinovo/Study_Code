#include <iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5,6};
    int *p=arr;
    cout <<sizeof(arr)/sizeof(arr[0])<<endl;
    for (int i = 0; i < (int)(sizeof(arr)/sizeof(arr[0])); i++)
    {
        cout << i << " is " << *p <<endl;
        cout <<i<< p<<endl;
        p++;
    }
    return 0;
}