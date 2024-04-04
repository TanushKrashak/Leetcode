
// DIFFICULTY: Medium
// Problem: 43. Multiply Strings
// Problem Link: https://leetcode.com/problems/multiply-strings/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string multiply(string num1, string num2) {
	int sizeA = num1.size();
	int sizeB = num2.size();
	int counter = 0;
	vector<int> ans;
	while (sizeB - counter > 0) {
		int iBonus = 0;
		for (int i = 0; i < counter; i++) {
			iBonus++;
		}
		for (int i = 0; i < sizeA; i++) {
			if (ans.size() <= i + iBonus)
				ans.push_back(0);
			ans[i + iBonus] = ans[i + iBonus] + (num1[sizeA - i - 1] - '0') * (num2[sizeB - counter - 1] - '0');
			int checkFor10P = i;
			while (ans[checkFor10P + iBonus] > 9) {
				if (ans.size() <= checkFor10P + 1 + iBonus)
					ans.push_back(0);
				ans[checkFor10P + 1 + iBonus] += (ans[checkFor10P + iBonus] / 10);
				ans[checkFor10P + iBonus] = ans[checkFor10P + iBonus] % 10;
				checkFor10P++;
			}
		}
		counter++;
	}

	string fAns = "";
	counter = ans.size();
	bool firstZero = true;
	for (int i = counter - 1; i >= 0; i--) {
		if (firstZero && char(ans[i] + '0') == '0')
			continue;
		firstZero = false;
		fAns += char(ans[i] + '0');
	}
	if (fAns == "")
		return "0";
	return fAns;
}
