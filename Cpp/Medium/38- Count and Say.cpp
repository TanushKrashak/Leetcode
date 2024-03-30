
// DIFFICULTY: Medium
// Problem: 38. Count and Say
// Problem Link: https://leetcode.com/problems/count-and-say/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string countAndSay(int n) {
    if (n == 1)
        return "1";
    string ans = countAndSay(n - 1);
    int counter = 0;
    int size = ans.size();
    while (counter < size) {
        char type = ans[counter];
        int currTypeCount = 0;
        while (counter + currTypeCount < size && type == ans[counter + currTypeCount]) {
            currTypeCount++;
        }
        ans.erase(counter, currTypeCount - 1);
        size -= currTypeCount - 1;
        ans.insert(ans.begin() + counter, char(currTypeCount) + '0');
        size++;
        counter += 2;
    }
    return ans;
}
