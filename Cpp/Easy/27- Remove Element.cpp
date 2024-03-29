
// DIFFICULTY: Easy
// Problem: 27. Remove Element
// Problem Link: https://leetcode.com/problems/remove-element/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int removeElement(vector<int>& nums, int val) {
	sort(nums.begin(), nums.end());
	int instances = 0;
	int firstIndex = -1;
	int size = nums.size();
	for (int i = 0; i < size; i++) {
		if (nums[i] == val) {
			instances++;
			if (firstIndex == -1)
				firstIndex = i;
		}
		else if (nums[i] > val)
			break;
	}
	int count = 0;
	while (instances > 0) {
		if (size - count - 1 > 0) {
			int temp = nums[firstIndex];
			nums[firstIndex] = nums[size - count - 1];
			nums[size - count - 1] = temp;
			firstIndex++;
		}
		instances--;
		count++;
	}
	return size - count;
}
