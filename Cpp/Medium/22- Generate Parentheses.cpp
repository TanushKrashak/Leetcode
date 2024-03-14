
// DIFFICULTY: Medium
// Problem: 22. Generate Parentheses
// Problem Link: https://leetcode.com/problems/generate-parentheses/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
bool isValid(string s) {
	int values = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			values++;
		}
		else {
			if (values == 0)
				return false;
			values--;
		}
	}
	if (values == 0)
		return true;
	return false;
}

vector<string> generateParenthesis(int n) {
	vector<string> finalList = {};
	string currStr = "";
	// Declare Indexes
	int oneCount = 0;
	for (int i = 0; i < (n * 2); i++) {
		if (i == (n * 2) - 1) {
			currStr += ')';
			oneCount++;
		}
		else {
			currStr += '(';
		}
	}
	int index = (n * 2) - 2;
	int smallestIndex = index;
	if (index < 1)
		return { "()" };
	while (true) {
		if (currStr[index] == '(') {
			currStr[index] = ')';
			oneCount++;
		}
		else {
			index--;
			if (index < 1)
				index = 1;
			if (index < smallestIndex)
				smallestIndex = index;
			if (index > 0 && currStr[index] != ')') {
				currStr[index] = ')';
				oneCount++;
				for (int i = index + 1; i < (n * 2) - 1; i++) {
					currStr[i] = '(';
					oneCount--;
				}
				index = (n * 2) - 2;
			}
		}

		if (oneCount == n && isValid(currStr) == 1) {
			bool shouldAdd = true;
			for (int i = 0; i < finalList.size(); i++) {
				if (currStr == finalList[i]) {
					shouldAdd = false;
					break;
				}
			}
			if (shouldAdd == true)
				finalList.push_back(currStr);
		}

		if ((smallestIndex == 1 && currStr[1] == ')') || index == 0) {
			if (index == 0)
				break;
			bool shouldStop = true;
			for (int i = 1; i < (n * 2) - 1; i++) {
				if (currStr[i] != ')') {
					shouldStop = false;
					break;
				}
			}
			if (shouldStop == true)
				break;
		}
	}
	return finalList;
}


