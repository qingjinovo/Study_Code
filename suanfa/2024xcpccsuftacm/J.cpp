#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool bool_n[n] = {false};
    for (int i = 0; i < n; i++)
    {
        if (bool_n[i])
            break;
        else
        {
            int j = i;
            while (i == a[j])
            {
                bool_n[j]=true;
                bool_n[bool_n[j]]=true;
                j=bool_n[j];
            }
        }
    }
    return 0;
}