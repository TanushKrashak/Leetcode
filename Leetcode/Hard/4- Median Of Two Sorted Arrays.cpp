
// DIFFICULTY: Hard
// Problem: 4. Median of Two Sorted Arrays
// Problem Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int countA = 0, countB = 0;
	while (countA < nums1.size() && countB < nums2.size()) {
		if (nums1[countA] < nums2[countB]) {
			countA++;
		}
		else {
			nums1.insert(nums1.begin() + countA, nums2[countB]);
			countB++;
		}
	}
	while (countB < nums2.size()) {
		nums1.push_back(nums2[countB]);
		countB++;
	}
	nums2.clear();
	if (nums1.size() % 2 == 0) 
		return double(nums1[nums1.size() / 2] + nums1[(nums1.size() / 2) - 1]) / 2;	
	else 
		return nums1[nums1.size() / 2];	
}
