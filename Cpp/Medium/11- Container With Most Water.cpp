
// DIFFICULTY: Medium
// Problem: 11. Container With Most Water
// Problem Link: https://leetcode.com/problems/container-with-most-water/

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
	int highest = 0;
	int tempHigh = 0;
	int left = 0;
	int right = int(height.size()) - 1;
	while (left < right) {
		tempHigh = min(height[left], height[right]) * (right - left);
		highest = max(highest, tempHigh);
		if (height[left] > height[right])
			right--;
		else
			left++;
	}
	return highest;
}
