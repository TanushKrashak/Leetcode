// DIFFICULTY: Easy
// Problem: 20. Valid Parentheses
// Problem Link: https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool isValid(string s) {
	string openBracks = "";
	if (s.size() % 2 == 1)
		return false;
	int index = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			openBracks += '(';
			index++;
		}
		else if (s[i] == '{') {
			openBracks += '{';
			index++;
		}
		else if (s[i] == '[') {
			openBracks += '[';
			index++;
		}
		else if (s[i] == ')') {
			if (index - 1 >= 0 && openBracks[index - 1] == '(') {
				if (openBracks.size() == 1)
					openBracks = "";
				else
					openBracks = openBracks.substr(0, index - 1);
				index--;
			}
			else
				return false;
		}
		else if (s[i] == '}') {
			if (index - 1 >= 0 && openBracks[index - 1] == '{') {
				if (openBracks.size() == 1)
					openBracks = "";
				else
					openBracks = openBracks.substr(0, index - 1);
				index--;
			}
			else
				return false;
		}
		else if (s[i] == ']') {
			if (index - 1 >= 0 && openBracks[index - 1] == '[') {
				if (openBracks.size() == 1)
					openBracks = "";
				else
					openBracks = openBracks.substr(0, index - 1);
				index--;
			}
			else
				return false;
		}
		else
			return false;
	}
	if (openBracks.size() == 0)
		return true;
	return false;
}
