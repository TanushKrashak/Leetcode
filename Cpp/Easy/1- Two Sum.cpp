// DIFFICULTY: Easy
// Problem: 1. Two Sum
// Problem Link: https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	for (int i = 0; i < nums.size() - 1; i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[i] + nums[j] == target)
				return { i,j };
		}
	}
	return {};
}

int main() {
	vector<int> nums = { 2,11,7,15 };
	int target = 9;
	vector<int> result = twoSum(nums, target);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}
