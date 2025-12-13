#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        
        // 使用二分查找找到第一个大于等于x的位置
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (a[mid] >= x)
                right = mid;
            else
                left = mid + 1;
        }
        
        // 检查是否找到了目标值
        if (left < n && a[left] == x)
            cout << left + 1 << ' ';
        else
            cout << "-1 ";
    }
    return 0;
}