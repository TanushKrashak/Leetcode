
// DIFFICULTY: Medium
// Problem: 56. Merge Intervals
// Problem Link: https://leetcode.com/problems/merge-intervals/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	int size = intervals.size();
	sort(intervals.begin(), intervals.end());
	vector<vector<int>> ans = { intervals[0] };
	int count = 0;
	for (int i = 1; i < size; i++) {
		if (ans[count][1] >= intervals[i][0]) {
			if (ans[count][0] > intervals[i][0] && ans[count][0] > intervals[i][1]) {
				ans.push_back({ intervals[i] });
				count++;
				continue;
			}
			if (ans[count][0] > intervals[i][0])
				ans[count][0] = intervals[i][0];
			if (ans[count][1] < intervals[i][1])
				ans[count][1] = intervals[i][1];
		}
		else {
			ans.push_back({ intervals[i] });
			count++;
		}
	}
	return ans;
}
