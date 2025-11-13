#include <iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5,6};
    int *p=arr;
    for (int i = 0; i < 6; i++)
    {
        cout << i << "is" << *p <<endl;
        i++;
    }
    
}