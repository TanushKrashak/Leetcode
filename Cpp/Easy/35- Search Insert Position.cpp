
// DIFFICULTY: Easy
// Problem: 35. Search Insert Position
// Problem Link: https://leetcode.com/problems/search-insert-position/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int size = nums.size();
    int left = 0, right = size - 1, center = (size - 1) / 2;
    while (left < right) {
        if (nums[center] == target) {
            return center;
        }
        if (right - left == 1) {
            if (nums[left] > target)
                return left;
            else if (nums[right] < target)
                return right + 1;
            return right;
        }
        else if (nums[center] > target) {
            right = center;
            center = (right + left) / 2;
            continue;
        }
        else {
            left = center;
            center = (right + left) / 2;
            continue;
        }
    }
    if (nums[center] < target)
        return center + 1;
    else
        return center;
}
