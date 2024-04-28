// DIFFICULTY: Easy
// Problem: 20. Valid Parentheses
// Problem Link: https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool isValid(string s) {
        int n = s.length(); // Store Length Of String
        stack<int> st; // Declaring Empty Stack To Keep Track Of Brackets
        for (int i = 0; i < n; i++) {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    char c = st.top();
                    st.pop();
                    if ((s[i] == ')' && c == '(') ||
                        (s[i] == ']' && c == '[') ||
                        (s[i] == '}' && c == '{')) {
                        continue;
                    } else {
                        return false;
                    }
                }
            }
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }
