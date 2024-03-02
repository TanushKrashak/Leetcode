// DIFFICULTY: Hard
// Problem: 10. Regular Expression Matching
// Problem Link: https://leetcode.com/problems/regular-expression-matching/

#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
	int m = s.length();
	int n = p.length();

	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;

	for (int i = 0; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (p[j - 1] == '*') {
				dp[i][j] = dp[i][j - 2];
				if (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
					dp[i][j] = dp[i][j] || dp[i - 1][j];
				}
			}
			else if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}

	return dp[m][n];
}
