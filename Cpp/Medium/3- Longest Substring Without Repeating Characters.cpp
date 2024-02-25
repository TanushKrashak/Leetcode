// DIFFICULTY: Medium
// Problem: 3. Longest Substring Without Repeating Characters
// Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
	string subStr = "", longestSubStr = "";
	int sSize = s.size();
	if (sSize == 1)
		return 1;
	int subSize = 0;
	for (int i = 0; i < sSize; i++) {
		bool add = true;
		int j;
		for (j = 0; j < subSize; j++) {
			if (s[i] == subStr[j]) {
				add = false;
				break;
			}
		}
		if (add == false) {
			string temp = subStr;
			subStr = "";
			subSize = 0;
			for (int k = j + 1; k < temp.size(); k++) {
				subStr += temp[k];
				subSize++;
			}
			subStr += s[i];
			subSize++;
		}
		else {
			subStr += s[i];
			subSize++;
			if (longestSubStr.size() < subSize)
				longestSubStr = subStr;
		}
	}
	return longestSubStr.size();
}
