
// DIFFICULTY: Medium
// Problem: 16. 3Sum Closest
// Problem Link: https://leetcode.com/problems/3sum-closest/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	int n = nums.size();
	sort(nums.begin(), nums.end());
	int currClosest = nums[0] + nums[1] + nums[2];
	int currDiff = abs(currClosest - target);
	for (int i = 0; i < n - 2; i++) {
		int left = i + 1;
		int right = n - 1;
		while (left < right && currClosest != target) {
			int sum = nums[i] + nums[left] + nums[right];
			if (sum == target) {
				currClosest = target;
				break;
			}
			else if (sum > currClosest) {
				// C > S > T 
				if (sum < target) {
					currClosest = sum;
					currDiff = abs(currClosest - target);
					left++;
				}
				// T < C < S 
				else if (currDiff < abs(sum - target))
					right--;
				// C < T < S 
				else if (currDiff > abs(sum - target)) {
					currClosest = sum;
					currDiff = abs(currClosest - target);
					right--;
				}
				// C < T < S 
				else
					right--;
			}
			else {
				// S < C < T 
				if (currClosest < target) {
					left++;
				}
				// S < T < C    
				else if (currDiff > abs(sum - target)) {
					currClosest = sum;
					currDiff = abs(currClosest - target);
					left++;
				}
				// T < S < C 
				else if (sum > target) {
					currClosest = sum;
					currDiff = abs(currClosest - target);
					right--;
				}
				// S < T < C 
				else
					left++;
			}
		}
	}
	return currClosest;
}
