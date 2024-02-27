// DIFFICULTY: Medium
// Problem: 5. Longest Palindromic Substring
// Problem Link: https://leetcode.com/problems/longest-palindromic-substring/

#include <iostream>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
	string longestPal = "";
	int n = s.size();

	for (int i = 0; i < n; i++) {
		// Check for odd-length palindromes with center at i
		int left = i, right = i;
		while (left >= 0 && right < n && s[left] == s[right]) {
			left--;
			right++;
		}
		int len = right - left - 1;
		if (len > longestPal.size()) {
			longestPal = s.substr(left + 1, len);
		}

		// Check for even-length palindromes with center between i and i+1
		left = i, right = i + 1;
		while (left >= 0 && right < n && s[left] == s[right]) {
			left--;
			right++;
		}
		len = right - left - 1;
		if (len > longestPal.size()) {
			longestPal = s.substr(left + 1, len);
		}
	}
	return longestPal;
}
