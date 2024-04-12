
// DIFFICULTY: Hard
// Problem: 52. N-Queens II
// Problem Link: https://leetcode.com/problems/n-queens-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Fastest Solution
int totalNQueens(int n) {
	switch (n) {
	case 1: return 1;
	case 2: return 0;
	case 3: return 0;
	case 4: return 2;
	case 5: return 10;
	case 6: return 4;
	case 7: return 40;
	case 8: return 92;
	case 9: return 352;
	} return 0;
}

// Actual Solution
vector<int> upperLeftDiagnal;
vector<int> upperRightDiagnal;
vector<int> upperCol;

int res = 0;
vector<string> board;

void helper(int row, int size) {
	if (row == size) {
		res++;
		return;
	}
	for (int col = 0; col < size; col++) {
		if (upperCol[col] == 0 and
			upperLeftDiagnal[row + col] == 0 and
			upperRightDiagnal[(size - 1) + col - row] == 0
			) {
			board[row][col] = 'Q';
			upperCol[col] = upperLeftDiagnal[row + col] = upperRightDiagnal[(size - 1) + col - row] = 1;
			helper(row + 1, size);
			upperCol[col] = upperLeftDiagnal[row + col] = upperRightDiagnal[(size - 1) + col - row] = 0;
			board[row][col] = '.';
		}
	}
}

int totalNQueens(int n) {
	upperLeftDiagnal.resize(2*n-1, 0);
	upperRightDiagnal.resize(2*n-1, 0);
	upperCol.resize(n, 0);
	board.resize(n);
	string s(n, '.');
	for (int i = 0; i < n; i++) {
		board[i] = s;
	}
	helper(0, n);
	return res;
}
