
// DIFFICULTY: Medium
// Problem: 31. Next Permutation
// Problem Link: https://leetcode.com/problems/next-permutation/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int size = nums.size();
    int probIndex = size - 1;
    if (size == 1)
        return;
    while (true) {
        probIndex--;
        if (nums[probIndex] < nums[probIndex + 1])
            break;
        if (probIndex <= 0)
            break;
    }
recheck:
    int justHighIndex = probIndex;
    for (int i = probIndex + 1; i < size; i++) {
        if (nums[probIndex] >= nums[justHighIndex]) {
            justHighIndex = i;
        }
        if (nums[i] > nums[probIndex] && nums[i] <= nums[justHighIndex]) {
            justHighIndex = i;
        }
    }
    if (nums[justHighIndex] < nums[probIndex]) {
        probIndex--;
        if (probIndex < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        goto recheck;
    }
    else {
        int temp = nums[justHighIndex];
        nums[justHighIndex] = nums[probIndex];
        nums[probIndex] = temp;
        probIndex++;
    }
    sort(nums.begin() + probIndex, nums.end());
    return;
}




