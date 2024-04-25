
// DIFFICULTY: Medium
// Problem: 62. Unique Paths
// Problem Link: https://leetcode.com/problems/unique-paths/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int uniquePaths(int m, int n) {
	unsigned int layer = m + n - 1;
	long long int total = 1;
	for (int j = 1; j <= layer; j++) {
		if (j == m || j == n)
			return total;
		total = (total * (layer - j)) / j;
	}
	return 1;
}
