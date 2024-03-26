
// DIFFICULTY: Medium
// Problem: 34. Find First and Last Position of Element in Sorted Array
// Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int size = nums.size();
    if (size == 1 && target == nums[0])
        return { 0,0 };
    int left = 0, right = size - 1, center = (right + left) / 2;
    bool found = 0, trig = 0;
    while (left < right) {
        if (nums[center] > target) {
            right = center;
            center = (right + left) / 2;
        }
        else if (nums[center] < target) {
            if (left == center) {
                center++;
                trig = 1;
                continue;
            }
            else {
                left = center;
                center = (right + left) / 2;
            }
        }
        else if (nums[center] == target) {
            found = 1;
            break;
        }
        if (trig == 1)
            break;
    }
    if (!found)
        return { -1,-1 };
    left = center, right = center;
    while (nums[left] == nums[center]) {
        left--;
        if (left < 0) {
            left = 0;
            break;
        }
    }
    if (nums[left] != nums[center])
        left++;
    while (nums[right] == nums[center]) {
        right++;
        if (right > size - 1) {
            right = size - 1;
            break;
        }
    }
    if (nums[right] != nums[center])
        right--;
    return { left, right };
}
