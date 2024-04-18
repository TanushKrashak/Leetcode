
// DIFFICULTY: Easy
// Problem: 58. Length of Last Word
// Problem Link: https://leetcode.com/problems/length-of-last-word/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int lengthOfLastWord(string s) {
	int size = s.size();
	string lastWord = ""; bool newWord = true;
	for (int i = 0; i < size; i++) {
		if (s[i] == ' ') {
			newWord = true;
			continue;
		}
		else if (newWord == true) {
			lastWord = "";
			newWord = false;
			lastWord += s[i];
		}
		else {
			lastWord += s[i];
		}
	}
	size = lastWord.size();
	return size;
}
