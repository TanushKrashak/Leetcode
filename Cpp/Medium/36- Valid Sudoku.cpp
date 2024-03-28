
// DIFFICULTY: Medium
// Problem: 36. Valid Sudoku
// Problem Link: https://leetcode.com/problems/valid-sudoku/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        int values[10] = { 0,0,0,0,0,0,0,0,0,0 };
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.')
                continue;
            if (values[board[i][j] - '0'] == 1) {
                return false;
            }
            values[board[i][j] - '0'] = 1;
        }
    }
    for (int i = 0; i < 9; i++) {
        int values[10] = { 0,0,0,0,0,0,0,0,0,0 };
        for (int j = 0; j < 9; j++) {
            if (board[j][i] == '.')
                continue;
            if (values[board[j][i] - '0'] == 1) {
                return false;
            }
            values[board[j][i] - '0'] = 1;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int values[10] = { 0,0,0,0,0,0,0,0,0,0 };
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    int cI = (i * 3) + l;
                    int cJ = (j * 3) + k;
                    if (board[cI][cJ] == '.')
                        continue;
                    if (values[board[cI][cJ] - '0'] == 1) {
                        return false;
                    }
                    values[board[cI][cJ] - '0'] = 1;
                }
            }
        }
    }
    return true;
}
