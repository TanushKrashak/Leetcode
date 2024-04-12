
// DIFFICULTY: Hard
// Problem: 51. N-Queens
// Problem Link: https://leetcode.com/problems/N-Queens

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool CanQueenBePlaced(vector<string>& board, int i, int j) {
	int size = board.size();
	for (int k = 0; k < size; k++) {
		// Check Row/Col
		if (board[i][k] == 'Q' || board[k][j] == 'Q')
			return false;
		// Check Top Left Diag
		if (i - k >= 0 && j - k >= 0 && board[i - k][j - k] == 'Q')
			return false;
		// Check Btm Right Diag
		if (i + k < size && j + k < size && board[i + k][j + k] == 'Q')
			return false;
		// Check Top Right Diag
		if (i - k >= 0 && j + k < size && board[i - k][j + k] == 'Q')
			return false;
		// Check Btm Left Diag
		if (i + k < size && j - k >= 0 && board[i + k][j - k] == 'Q')
			return false;
	}
	return true;
}

void FindAllSolutions(vector<string>& board, int i, int counter, vector<vector<string>>& ans) {
	if (i >= board.size()) {
		// Check If All Ways Done
		if (counter == 0)
			ans.push_back(board);
		return;
	}
	for (int j = 0; j < board.size(); j++) {
		if (CanQueenBePlaced(board, i, j)) {
			board[i][j] = 'Q';
			FindAllSolutions(board, i + 1, counter - 1, ans);
			board[i][j] = '.';
		}
	}
}

vector<vector<string>> solveNQueens(int size) {
	vector<vector<string>> ans;
	vector<string> board(size, "");
	// Put In Format .... , .... for n=4 etc
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++)
			board[x].push_back('.');
	}
	for (int y = 0; y < size; y++) {
		board[0][y] = 'Q';
		FindAllSolutions(board, 1, size - 1, ans);
		board[0][y] = '.'; // Revert & Move on
	}
	return ans;
}

