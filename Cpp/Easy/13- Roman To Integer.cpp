// DIFFICULTY: Easy
// Problem: 13. Roman to Integer
// Problem Link: https://leetcode.com/problems/roman-to-integer/

#include <iostream>
#include <vector>

using namespace std;

static int romanToInt(string s) {
	char charNames[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	int charValues[7] = { 1, 5, 10, 50, 100, 500, 1000 };
	char* pS = &s[0];
	int len = s.length();
	// Main Code
	int curIndex = 0, num = 0, curStacks = 0;
	while (curIndex < len) {
		int indexIncr = 0;
		// Calculate How Many Times Same Num Repeats In A Row!
		if (curIndex + 1 < len && pS[curIndex] == pS[curIndex + 1]) {
			if (curIndex + 2 < len && pS[curIndex] == pS[curIndex + 2]) {
				curStacks = 3;
				indexIncr += 3;
			}
			else {
				curStacks = 2;
				indexIncr += 2;
			}
			int addIndex;
			for (int i = 0; i < 7; i++) {
				if (pS[curIndex] == charNames[i]) {
					addIndex = i;
					break;
				}
			}
			num = num + (charValues[addIndex] * curStacks);
		}
		// Comboin Numbers!
		else {
			// For I (1)
			if (pS[curIndex] == charNames[0]) {
				if (curIndex + 1 < len && pS[curIndex + 1] == charNames[1])
					num += 4;
				else if (curIndex + 1 < len && pS[curIndex + 1] == charNames[2])
					num += 9;
				else {
					num += 1;
					indexIncr += -1;
				}
			}
			// For V (5)
			if (pS[curIndex] == charNames[1]) {
				num += 5;
				indexIncr += -1;
			}
			// For X (10)
			if (pS[curIndex] == charNames[2]) {
				if (curIndex + 1 < len && pS[curIndex + 1] == charNames[3])
					num += 40;
				else if (curIndex + 1 < len && pS[curIndex + 1] == charNames[4])
					num += 90;
				else {
					num += 10;
					indexIncr += -1;
				}
			}
			// For L (50)
			if (pS[curIndex] == charNames[3]) {
				num += 50;
				indexIncr += -1;
			}
			// For C (100)
			if (pS[curIndex] == charNames[4]) {
				if (curIndex + 1 < len && pS[curIndex + 1] == charNames[5])
					num += 400;
				else if (curIndex + 1 < len && pS[curIndex + 1] == charNames[6])
					num += 900;
				else {
					num += 100;
					indexIncr += -1;
				}
			}
			// For D (500)
			if (pS[curIndex] == charNames[5]) {
				num += 500;
				indexIncr += -1;
			}
			// For M (1000)
			if (pS[curIndex] == charNames[6]) {
				num += 1000;
				indexIncr += -1;
			}
			indexIncr += 2;
		}
		curIndex += indexIncr;
	}
	return num;
}
