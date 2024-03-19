
// DIFFICULTY: Easy
// Problem: 26. Remove Duplicates from Sorted Array
// Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int count = 0;
    int size = nums.size();
    int i = 0;
    while (i < size) {
        count++;
        while (i + 1 < size && nums[i] == nums[i + 1]) {
            i++;
        }
        i++;
        if (i < size) {
            nums[count] = nums[i];
        }
    }
    return count;
}



