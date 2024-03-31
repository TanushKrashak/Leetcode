
// DIFFICULTY: Medium
// Problem: 39. Combination Sum
// Problem Link: https://leetcode.com/problems/combination-sum/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void sum(vector<vector<int>>& finalAns, vector<int> ans, int value, int target, vector<int>& candidates, int index) {
    ans.push_back(value);
    target -= value;
    if (target == 0) {
        finalAns.push_back(ans);
        return;
    }
    else if (target < 0) {
        return;
    }
    int size = candidates.size();
    for (int i = index; i < size; i++) {
        sum(finalAns, ans, candidates[i], target, candidates, i);
    }
    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int size = candidates.size();
    vector<vector<int>> finalAns;
    for (int i = 0; i < size; i++) {
        sum(finalAns, {}, candidates[i], target, candidates, i);
    }
    return finalAns;
}

