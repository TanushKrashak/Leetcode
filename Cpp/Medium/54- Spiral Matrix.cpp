
// DIFFICULTY: Medium
// Problem: 54. Spiral Matrix
// Problem Link: https://leetcode.com/problems/spiral-matrix/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	vector<int> ans;
	for (int layer = 0; layer < min((m + 1) / 2, (n + 1) / 2); layer++) {
		bool trig1 = false;
		// traversing row L->R
		for (int i = layer; i < n - layer; i++)
			ans.push_back(matrix[layer][i]);

		bool trig2 = false;
		// traversing col T->B
		for (int i = layer + 1; i < m - layer; i++) {
			ans.push_back(matrix[i][n - layer - 1]);
			trig2 = true;
		}

		if (trig2) {
			// traversing row R->L
			for (int i = n - layer - 2; i >= layer; i--) {
				ans.push_back(matrix[m - layer - 1][i]);
				trig1 = true;
			}
		}
		if (trig1) {
			// traversing col B->T
			for (int i = m - layer - 2; i > layer; i--)
				ans.push_back(matrix[i][layer]);
		}
	}
	return ans;
}
