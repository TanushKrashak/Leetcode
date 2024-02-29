
// DIFFICULTY: Medium
// Problem: 6. ZigZag Conversion
// Problem Link: https://leetcode.com/problems/zigzag-conversion/

#include <iostream>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
	int perSet = (numRows * 2) - 2;
	if (perSet == 0)
		return s;
	int size = s.size();
	string finalStr = "";
	for (int i = 0; i < numRows; i++) {
		int numPerRow = 2;
		if (i == 0 || i == numRows - 1) {
			numPerRow = 1;
		}
		int index = i;
		if (index >= size)
			return finalStr;
		bool flip = true;
		while (true) {
			finalStr += s[index];
			if (flip == true)
				index = index + perSet;
			if (numPerRow == 2) {
				if (flip == true) {
					flip = false;
					index -= (2 * i);
				}
				else {
					flip = true;
					index = index + (2 * i);
				}
			}
			if (index >= size) {
				break;
			}
		}
	}
	return finalStr;
}
