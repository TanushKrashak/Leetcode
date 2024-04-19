
// DIFFICULTY: Medium
// Problem: 59. Spiral Matrix II
// Problem Link: https://leetcode.com/problems/spiral-matrix-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
	vector<int> temp(n, 0);
	vector<vector<int>> ans;
	for (int i = 0; i < n; i++) {
		ans.push_back(temp);
	}
	int count = 1;
	for (int layer = 0; layer < (n + 1) / 2; layer++) {
		bool trig1 = false;
		// traversing row L->R
		for (int i = layer; i < n - layer; i++) {
			ans[layer][i] = count;
			count++;
		}

		bool trig2 = false;
		// traversing col T->B
		for (int i = layer + 1; i < n - layer; i++) {
			ans[i][n - layer - 1] = count;
			trig2 = true;
			count++;
		}

		if (trig2) {
			// traversing row R->L
			for (int i = n - layer - 2; i >= layer; i--) {
				ans[n - layer - 1][i] = count;
				trig1 = true;
				count++;
			}
		}
		if (trig1) {
			// traversing col B->T
			for (int i = n - layer - 2; i > layer; i--) {
				ans[i][layer] = count;
				count++;
			}
		}
	}
	return ans;
}
