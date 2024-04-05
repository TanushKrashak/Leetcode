// DIFFICULTY: Medium
// Problem: 45. Jump Game II
// Problem Link: https://leetcode.com/problems/jump-game-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int jump(vector<int>& nums) {
	int n = nums.size();
	int jumps = 0;
	int farthest = 0;
	int right = 0;

	for (int i = 0; i < n - 1; i++) {
		farthest = max(farthest, i + nums[i]);
		if (i == right) {
			jumps++;
			right = farthest;
		}
	}
	return jumps;
}
