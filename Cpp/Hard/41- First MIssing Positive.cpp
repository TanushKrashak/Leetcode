
// DIFFICULTY: Hard
// Problem: 41. First Missing Positive
// Problem Link: https://leetcode.com/problems/first-missing-positive/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		if (nums[i] <= 0)
			nums[i] = n + 1;
	}

	for (int i = 0; i < n; i++) {
		if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0)
			nums[abs(nums[i]) - 1] *= -1;
	}

	for (int i = 0; i < n; i++) {
		if (nums[i] > 0)
			return i + 1;
	}
	return n + 1;
}
