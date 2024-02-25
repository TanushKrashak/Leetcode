
// DIFFICULTY: Easy
// Problem: 1. Two Sum
// Problem Link: 

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


