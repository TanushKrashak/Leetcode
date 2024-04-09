
// DIFFICULTY: Medium
// Problem: 49. Group Anagrams
// Problem Link: https://leetcode.com/problems/group-anagrams/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct strData {
	string str;
	int index;
	strData(string s, int i) {
		str = s;
		index = i;
	}
	bool operator<(const strData& a) const {
		return (str < a.str);
	}
};
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	int size = strs.size();
	vector<strData> newStrs;
	for (int i = 0; i < size; i++) {
		newStrs.push_back(strData(strs[i], i));
		sort(newStrs[i].str.begin(), newStrs[i].str.end());
	}
	sort(newStrs.begin(), newStrs.end());
	vector<vector<string>> ans;
	string prev = ".";
	int ansVal = -1;
	for (int i = 0; i < size; i++) {
		if (prev != newStrs[i].str) {
			ansVal++;
			ans.push_back({ strs[newStrs[i].index] });
			prev = newStrs[i].str;
		}
		else {
			ans[ansVal].push_back(strs[newStrs[i].index]);
		}
	}
	return ans;
}


