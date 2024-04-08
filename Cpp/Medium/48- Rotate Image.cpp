
// DIFFICULTY: Medium
// Problem: 48. Rotate Image
// Problem Link: https://leetcode.com/problems/rotate-image/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	for (int layer = 0; layer < n / 2; layer++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n - 1 - (layer * 2); j++) {
				if (i == 0) {
					int temp = matrix[i + layer][j + layer];
					matrix[i + layer][j + layer] = matrix[n - j - 1 - layer][i + layer];
					matrix[n - j - 1 - layer][i + layer] = temp;
				}
				else if (i == 1) {
					int temp = matrix[j + 1 + layer][i - 1 + layer];
					matrix[j + 1 + layer][i - 1 + layer] = matrix[n - i - layer][j + 1 + layer];
					matrix[n - i - layer][j + 1 + layer] = temp;
				}
				else {
					int temp = matrix[n - 1 - layer][j + 1 + layer];
					matrix[n - 1 - layer][j + 1 + layer] = matrix[n - (i + j) - layer][n - 1 - layer];
					matrix[n - (i + j) - layer][n - 1 - layer] = temp;
				}
			}

		}
	}
}
