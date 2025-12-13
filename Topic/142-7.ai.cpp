#include <iostream>
using namespace std;
int main()
{
    // 提供一个更容易观察鞍点的例子
    // 在这个矩阵中，3在位置(2,1)是一个鞍点：
    // 它是所在行的最小值，也是所在列的最大值
    int a[5][5] = {{1, 2, 3, 4, 5},
                   {5, 6, 7, 8, 9},
                   {9, 3, 1, 2, 0},  // 第2行，第1列的3是这一行的最小值
                   {4, 5, 6, 7, 8},
                   {8, 9, 1, 3, 4}};
                   
    bool found = false;
    
    // 遍历每一行
    for (int i = 0; i < 5; i++) {
        // 找到第i行的最小值列索引
        int min_col = 0;
        for (int j = 1; j < 5; j++) {
            if (a[i][j] < a[i][min_col]) {
                min_col = j;
            }
        }
        
        // 检查该位置是否是所在列的最大值
        bool isMaxInCol = true;
        for (int k = 0; k < 5; k++) {
            if (a[k][min_col] > a[i][min_col]) {
                isMaxInCol = false;
                break;
            }
        }
        
        if (isMaxInCol) {
            cout << "找到鞍点: " << a[i][min_col] << " 在位置 (" << i << "," << min_col << ")" << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "没有找到鞍点" << endl;
    }
    
    return 0;
}