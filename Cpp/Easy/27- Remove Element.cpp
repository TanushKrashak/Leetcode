
// DIFFICULTY: Easy
// Problem: 27. Remove Element
// Problem Link: https://leetcode.com/problems/remove-element/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int removeElement(vector<int>& nums, int val) {
	sort(nums.begin(), nums.end()); // Sort to keep all instances together
	int instances = 0; // Count of how many times 'val' appears in the vector
	int firstIndex = -1; // Index of the first occurrence of 'val'
	int size = nums.size();

	// Iterate through the vector to find all occurrences of 'val'
	for (int i = 0; i < size; i++) { 
		if (nums[i] == val) {
			instances++;
			if (firstIndex == -1)
				firstIndex = i; // Set the index of the first occurrence of 'val'
		}
		else if (nums[i] > val) {
 			// Since the vector is sorted, we can stop the loop if we encounter a number greater than 'val'
			break;
		}
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
