
// DIFFICULTY: Medium
// Problem: 47. Permutations II
// Problem Link: https://leetcode.com/problems/permutations-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void nextPermutation(vector<int>& nums, int size) {
	int probIndex = size - 1;
	if (size == 1)
		return;
	while (true) {
		probIndex--;
		if (nums[probIndex] < nums[probIndex + 1])
			break;
		if (probIndex <= 0)
			break;
	}
recheck:
	int justHighIndex = probIndex;
	for (int i = probIndex + 1; i < size; i++) {
		if (nums[probIndex] >= nums[justHighIndex]) {
			justHighIndex = i;
		}
		if (nums[i] > nums[probIndex] && nums[i] <= nums[justHighIndex]) {
			justHighIndex = i;
		}
	}
	if (nums[justHighIndex] < nums[probIndex]) {
		probIndex--;
		if (probIndex < 0) {
			sort(nums.begin(), nums.end());
			return;
		}
		goto recheck;
	}
	else {
		int temp = nums[justHighIndex];
		nums[justHighIndex] = nums[probIndex];
		nums[probIndex] = temp;
		probIndex++;
	}
	sort(nums.begin() + probIndex, nums.end());
	return;
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int size = nums.size();
	vector<int> start = nums;
	vector<vector<int>> ans;
	nextPermutation(nums, size);
	ans.push_back(nums);
	while (start != nums) {
		nextPermutation(nums, size);
		ans.push_back(nums);
	}
	return ans;
}

