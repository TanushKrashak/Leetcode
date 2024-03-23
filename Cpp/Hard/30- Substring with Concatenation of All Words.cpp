
// DIFFICULTY: Hard
// Problem: 30. Substring with Concatenation of All Words
// Problem Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool IsSubStr(string s, int wordLen, unordered_map<string, int> wordCount) {
    for (int i = 0; i < s.size(); i += wordLen) {
        string word = s.substr(i, wordLen);
        if (wordCount.find(word) != wordCount.end()) {
            wordCount[word]--;
            if (wordCount[word] < 0)
                return false;
        }
        else
            return false;
    }
    return true;
}

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;

    int wordLen = words[0].size();  // Length of each word in words.
    int totalLen = wordLen * words.size();  // Total length of all words combined.

    unordered_map<string, int> wordCount;  // Map to store the count of each word in String.
    for (const string& word : words) {
        wordCount[word]++;
    }
    int i = 0;
    while (i + totalLen <= s.size()) {
        if (IsSubStr(s.substr(i, totalLen), wordLen, wordCount))
            result.push_back(i);
        i++;
    }

    return result;
}



