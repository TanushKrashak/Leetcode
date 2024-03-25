
// DIFFICULTY: Medium
// Problem: 33. Search in Rotated Sorted Array
// Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int search(vector<int>& nums, int target) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (nums[i] == target)
            return i;
    }
    return -1;
}


