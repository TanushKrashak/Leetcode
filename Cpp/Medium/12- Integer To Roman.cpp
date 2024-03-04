
// DIFFICULTY: Medium
// Problem: 12. Integer to Roman
// Problem Link: https://leetcode.com/problems/integer-to-roman/

#include <iostream>
#include <vector>

using namespace std;

string intToRoman(int num) {
	string finalStr = "";
	while (num != 0) {
		if (num >= 1000) {
			num -= 1000;
			finalStr += 'M';
		}
		else if (num >= 900) {
			num -= 900;
			finalStr += "CM";
		}
		else if (num >= 500) {
			num -= 500;
			finalStr += "D";
		}
		else if (num >= 400) {
			num -= 400;
			finalStr += "CD";
		}
		else if (num >= 100) {
			num -= 100;
			finalStr += "C";
		}
		else if (num >= 90) {
			num -= 90;
			finalStr += "XC";
		}
		else if (num >= 50) {
			num -= 50;
			finalStr += "L";
		}
		else if (num >= 40) {
			num -= 40;
			finalStr += "XL";
		}
		else if (num >= 10) {
			num -= 10;
			finalStr += "X";
		}
		else if (num >= 9) {
			num -= 9;
			finalStr += "IX";
		}
		else if (num >= 5) {
			num -= 5;
			finalStr += "V";
		}
		else if (num >= 4) {
			num -= 4;
			finalStr += "IV";
		}
		else {
			num -= 1;
			finalStr += "I";
		}
	}
	return finalStr;
}
