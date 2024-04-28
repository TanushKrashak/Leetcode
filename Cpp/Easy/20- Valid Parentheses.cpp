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
                    char c = st.top(); // Get the latest Pushed Bracket
                    st.pop(); // Pop it out so that the next bracket can be used the next time
                    if ((s[i] == ')' && c == '(') || (s[i] == ']' && c == '[') || (s[i] == '}' && c == '{')) // Both String Char and Poped Out Bracket are of same type
                        continue;                    
                    else // Not a Closing Bracket OR Mismatched Bracket
                        return false;                    
                }
            }
        }
        if (st.empty()) { // Only If stack is empty can it be valid as all brackets were cancelled out
            return true;
        }
        return false;
    }
