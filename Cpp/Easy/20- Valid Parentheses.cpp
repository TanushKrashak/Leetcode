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
        for (int i = 0; i < n; i++) { // Loop Through Entire String
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') // Check if Char is Open Bracket, if so push to stack
                st.push(s[i]);        
            else {
                if (st.empty()) // If Stack is empty, No need to check For Close Bracket
                    return false;
                else {
                    char c = st.top();
                    st.pop();
                    if ((s[i] == ')' && c == '(') ||
                        (s[i] == ']' && c == '[') ||
                        (s[i] == '}' && c == '{')) {
                        continue;
                    } 
                    else // Not a Closing Bracket OR Mismatched Bracket
                        return false;                    
                }
            }
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }
