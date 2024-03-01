
// DIFFICULTY: Medium
// Problem: 8. String to Integer (atoi)
// Problem Link: https://leetcode.com/problems/string-to-integer-atoi/

#include <iostream>
#include <vector>

using namespace std;

int myAtoi(string s) {
	char neg = '0';
	int finalNum = 0;
	int numAlrDone = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-') {
			if (numAlrDone == 1)
				break;
			else if (neg > '0') {
				finalNum = 0;
				break;
			}
			neg = '2';
		}
		else if (s[i] == '+') {
			if (numAlrDone == 1)
				break;
			else if (neg > '0') {
				finalNum = 0;
				break;
			}
			neg = '1';
		}
		else if (numAlrDone != 2 && s[i] >= '0' && s[i] <= '9') {
			numAlrDone = 1;
			if (neg == '2' && (long long int)(finalNum) * 10 + s[i] - '0' >= pow(2, 31)) {
				finalNum = (long long int) - 1 * pow(2, 31);
				neg = '0';
				break;
			}
			else if ((long long int)(finalNum) * 10 + s[i] - '0' >= pow(2, 31) - 1) {
				finalNum = pow(2, 31) - 1;
				break;
			}
			else
				finalNum = finalNum * 10 + int(s[i] - '0');
		}
		else if (s[i] != ' ') {
			if (numAlrDone == 1 || s[i] == '.') {
				break;
			}
			else
				finalNum = 0;
			break;
		}
		else {
			if (numAlrDone == 1)
				break;
			if (s[i] == ' ' && neg > '0')
				break;
		}
	}
	if (neg == '2')
		finalNum *= -1;
	return finalNum;
}
