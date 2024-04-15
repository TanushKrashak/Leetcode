
// DIFFICULTY: Medium
// Problem: 55. Jump Game
// Problem Link: https://leetcode.com/problems/jump-game/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool canJump(vector<int>& nums) {
	int n = nums.size();
	int jump = 0;
	int left = 0, right = 0;
	for (int i = 0; i < n - 1; i++) {
		if (right >= i && nums[i] > 0) {
			left = i + 1;
			right = max(right, i + nums[i]);
			if (right >= n - 1)
				return true;
		}
	}
	if (right >= n - 1)
		return true;
	return false;
}
