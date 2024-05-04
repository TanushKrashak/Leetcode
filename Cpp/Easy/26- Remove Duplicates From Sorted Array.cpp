
// DIFFICULTY: Easy
// Problem: 26. Remove Duplicates from Sorted Array
// Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int count = 0; // Initialize a counter to keep track of unique elements
    int size = nums.size(); /// Store size of array
    int i = 0; // Loop Counter
    while (i < size) {
        count++; // Increment for each unique element
        // Move the pointer to the last occurrence of the current element
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



