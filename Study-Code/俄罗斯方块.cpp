#include <iostream>
#include <vector>
#include <algorithm>

class GameBoard {
public:
    GameBoard() : score(0) {
        // 初始化一个 10x20 的棋盘，用 '.' 表示空格
        board.resize(20, std::vector<char>(10, '.'));
    }

    bool canMove(int row, int col, const std::vector<std::vector<char>>& shape) const {
        // 检查形状是否可以放置在指定位置
        for (int i = 0; i < shape.size(); ++i) {
            for (int j = 0; j < shape[i].size(); ++j) {
                if (shape[i][j] == '#' && 
                    (row + i >= board.size() || col + j >= board[0].size() || 
                     board[row + i][col + j] != '.')) {
                    return false;
                }
            }
        }
        return true;
    }

    void placeShape(int row, int col, const std::vector<std::vector<char>>& shape) {
        // 在指定位置放置形状
        for (int i = 0; i < shape.size(); ++i) {
            for (int j = 0; j < shape[i].size(); ++j) {
                if (shape[i][j] == '#') {
                    board[row + i][col + j] = '#';
                }
            }
        }
    }

    void removeFullLines() {
        // 检查并移除满行
        std::vector<bool> fullLines(board.size(), false);
        for (int row = 0; row < board.size(); ++row) {
            int count = 0;
            for (char cell : board[row]) {
                if (cell == '#') {
                    count++;
                }
            }
            fullLines[row] = count == board[0].size();
        }

        if (std::any_of(fullLines.begin(), fullLines.end(), [](bool line) { return line; })) {
            for (int row = board.size() - 1; row >= 0; --row) {
                if (fullLines[row]) {
                    board.erase(board.begin() + row);
                    board.insert(board.begin(), std::vector<char>(board[0].size(), '.'));
                    score += 10; // 每移除一行增加10分
                }
            }
        }
    }

    void draw() const {
        // 绘制棋盘
        for (const auto& row : board) {
            for (char cell : row) {
                std::cout << (cell == '#' ? "X" : ".") << " ";
            }
            std::cout << "\n";
        }
    }

    int score; // 游戏分数
    std::vector<std::vector<char>> board; // 游戏棋盘
};

int main() {
    GameBoard board;

    // 假设 shape 是一个有效的二维数组
    std::vector<std::vector<char>> shape = {
        {'X', 'X', 'X'},
        {'X', '.', '.'}, 
        {'.', '.', '.'}
    };

    int row = 0, col = 3;

    while (true) {
        if (!board.canMove(row, col, shape)) {
            break;
        }
        // 放置形状
        board.placeShape(row, col, shape);
        board.score++; // 增加分数

        board.removeFullLines();
        board.draw();

        // 模拟下落一行
        row++;
    }

    std::cout << "Final Score: " << board.score << "\n";

    return 0;
}