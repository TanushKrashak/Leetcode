
// DIFFICULTY: Hard	
// Problem: 44. Wildcard Matching
// Problem Link: https://leetcode.com/problems/wildcard-matching/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

bool isMatch(string s, string p) {
	int StringSize = s.size();
	int PatternSize = p.size();
	vector<vector<bool>> dp(StringSize + 1, vector<bool>(PatternSize + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= PatternSize; i++) {
		if (p[i - 1] == '*') {
			dp[0][i] = dp[0][i - 1];
		}
	}
	for (int i = 1; i <= StringSize; i++) {
		for (int j = 1; j <= PatternSize; j++) {
			if (p[j - 1] == '*') {
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
			}
			else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}
	return dp[StringSize][PatternSize];
}

