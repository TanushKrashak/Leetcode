
    // DIFFICULTY: Medium
    // Problem: 40. Combination Sum II
    // Problem Link: https://leetcode.com/problems/combination-sum-ii/

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <unordered_map>

    using namespace std;

    void sum(vector<vector<int>>& finalAns, vector<int> ans, int value, int target, vector<int>& candidates, int index) {
        ans.push_back(value);
        target -= value;
        if (target == 0) {
            int size = finalAns.size();
            for (int i = 0; i < size; i++) {
                if (finalAns[i] == ans)
                    return;
            }
            finalAns.push_back(ans);
            return;
        }
        else if (target < 0) {
            return;
        }
        int size = candidates.size();
        for (int i = index + 1; i < size; i++) {
            if (i > index + 1 && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            sum(finalAns, ans, candidates[i], target, candidates, i);
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int size = candidates.size();
        vector<vector<int>> finalAns;
        for (int i = 0; i < size; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1]) continue;
            sum(finalAns, {}, candidates[i], target, candidates, i);
        }
        return finalAns;
    }
