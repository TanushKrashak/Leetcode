
// DIFFICULTY: Medium
// Problem: 53. Maximum Subarray
// Problem Link: https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int maxSubArray(vector<int>& nums) {
	int size = nums.size();
	int highestSum = nums[0];
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += nums[i];
		highestSum = max(sum, highestSum);
		sum = max(sum, 0);
	}
	return highestSum;
}
