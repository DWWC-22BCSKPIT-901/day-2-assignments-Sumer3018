#include <iostream>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> rows(9, vector<bool>(9, false)), cols(9, vector<bool>(9, false)), boxes(9, vector<bool>(9, false));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') continue;
            int num = board[i][j] - '1';
            int boxIndex = (i / 3) * 3 + j / 3;
            if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) return false;
            rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    bool validSudoku = isValidSudoku(board);
    cout << (validSudoku ? "Valid Sudoku" : "Invalid Sudoku") << endl;
    return 0;
}
