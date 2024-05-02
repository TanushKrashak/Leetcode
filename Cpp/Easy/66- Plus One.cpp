
// DIFFICULTY: Easy
// Problem: 66. Plus One
// Problem Link: https://leetcode.com/problems/plus-one/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	int count = digits.size() - 1;
	while(count >= 0) {
		if(digits[count] != 9) {
			digits[count]++;
			return digits;
		}
		else {
			digits[count] = 0;
			count--;
			if(count < 0) {
				digits.insert(digits.begin(), 1);
			}
			continue;
		}
	}
	return digits;
}
