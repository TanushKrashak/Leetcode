// DIFFICULTY: Easy
// Problem: 1. Two Sum
// Problem Link: https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	int size = nums.size(); // Store Size Of Nums
	for (int i = 0; i < size - 1; i++) { // Go Through Nums
		for (int j = i + 1; j < size; j++) { // Go Through Remaining Part Of Nums
			if (nums[i] + nums[j] == target) // Check If 2 Sum
				return { i,j };
		}
	}
	return {}; // Return Null As No Answer Found
}

