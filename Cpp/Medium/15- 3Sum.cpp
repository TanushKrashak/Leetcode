
// DIFFICULTY: Easy
// Problem: 15. 3Sum
// Problem Link: https://leetcode.com/problems/3sum/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> finalOutput;
	int n = nums.size();
	sort(nums.begin(), nums.end());

	for (int i = 0; i < n - 2; i++) {
		if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
			int left = i + 1;
			int right = n - 1;
			int target = -nums[i];

			while (left < right) {
				int sum = nums[left] + nums[right];

				if (sum == target) {
					finalOutput.push_back({ nums[i], nums[left], nums[right] });

					while (left < right && nums[left] == nums[left + 1])
						left++;
					while (left < right && nums[right] == nums[right - 1])
						right--;

					left++;
					right--;
				}
				else if (sum < target) {
					left++;
				}
				else {
					right--;
				}
			}
		}
	}

	return finalOutput;
}

