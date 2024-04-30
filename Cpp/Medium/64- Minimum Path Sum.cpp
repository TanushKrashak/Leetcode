
// DIFFICULTY: Medium
// Problem: 64. Minimum Path Sum
// Problem Link: https://leetcode.com/problems/minimum-path-sum/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int calcMinSum(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j, int sum = 0) {
	if(i < 0 || j < 0)
		return INT_MAX;
	sum += grid[i][j];
	if(i == 0 && j == 0) {
		dp[i][j] = 0;
		return sum;
	}
	if(dp[i][j] != -1) {
		sum += dp[i][j];
		return sum;
	}
	int up = calcMinSum(grid, dp, i - 1, j);
	int left = calcMinSum(grid, dp, i, j - 1);
	dp[i][j] = min(up, left);
	return sum + dp[i][j];
}

int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> dp(m, vector<int>(n, -1));
	calcMinSum(grid, dp, m - 1, n - 1, 0);
	return dp[m - 1][n - 1] + grid[m - 1][n - 1];
}
