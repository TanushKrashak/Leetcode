
// DIFFICULTY: Medium
// Problem: 57. Insert Interval
// Problem Link: https://leetcode.com/problems/merge-intervals/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	int size = intervals.size();
	if (size == 0)
		intervals.push_back(newInterval);
	for (int i = size - 1; i >= 0; i--) {
		if (newInterval[0] > intervals[i][0]) {
			intervals.insert(intervals.begin() + i + 1, newInterval);
			break;
		}
	}
	if (size == intervals.size())
		intervals.insert(intervals.begin(), newInterval);
	vector<vector<int>> ans = { intervals[0] };
	int count = 0;
	for (int i = 1; i < size + 1; i++) {
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

