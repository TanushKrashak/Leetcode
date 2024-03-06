
// DIFFICULTY: Easy
// Problem: 14. Longest Common Prefix
// Problem Link: https://leetcode.com/problems/longest-common-prefix/

#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	string commonPrefix = strs[0];
	for (int i = 1; i < strs.size(); i++) {
		string newCommonPrefix = "";
		for (int letter = 0; letter < strs[i].length(); letter++) {
			if (letter < commonPrefix.length() && commonPrefix[letter] == strs[i][letter])
				newCommonPrefix += commonPrefix[letter];
			else
				break;
		}
		commonPrefix = newCommonPrefix;
	}
	return commonPrefix;
}
