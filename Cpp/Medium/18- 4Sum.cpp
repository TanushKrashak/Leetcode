
// DIFFICULTY: Medium
// Problem: 18. 4Sum
// Problem Link: https://leetcode.com/problems/4sum/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	if (nums[nums.size() - 1] > pow(2, 31) || nums[0] < -pow(2, 31))
		return { {} };
	int firstVal = 0, secondVal = 1, thirdVal, forthVal;
	vector<vector<int>> finalOutput;
	while (firstVal <= int(nums.size()) - 4) {
		secondVal = firstVal + 1;
		while (secondVal <= int(nums.size()) - 3) {
			thirdVal = secondVal + 1;
			forthVal = nums.size() - 1;
			while (thirdVal < forthVal) {
				long long sum = static_cast<long long>(nums[firstVal]) + nums[secondVal] + nums[thirdVal] + nums[forthVal];
				if (sum > target)
					forthVal--;
				else if (sum < target)
					thirdVal++;
				else {
					bool addVal = true;
					for (int i = 0; i < finalOutput.size(); i++) {
						if (finalOutput[i] == vector<int>{ nums[firstVal], nums[secondVal], nums[thirdVal], nums[forthVal] }) {
							addVal = false;
							break;
						}
					}
					if (addVal == true) {
						finalOutput.push_back({ nums[firstVal], nums[secondVal], nums[thirdVal], nums[forthVal] });
					}
					while (thirdVal < forthVal && nums[thirdVal] == nums[thirdVal + 1])
						thirdVal++;
					while (thirdVal < forthVal && nums[forthVal] == nums[forthVal - 1])
						forthVal--;
					thirdVal++;
					forthVal--;
				}
			}
			while (secondVal <= int(nums.size()) - 3 && nums[secondVal] == nums[secondVal + 1])
				secondVal++;
			secondVal++;
		}
		while (firstVal <= int(nums.size()) - 4 && nums[firstVal] == nums[firstVal + 1])
			firstVal++;
		firstVal++;
	}
	return finalOutput;
}

