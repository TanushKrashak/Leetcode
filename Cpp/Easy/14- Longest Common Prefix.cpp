
// DIFFICULTY: Easy
// Problem: 14. Longest Common Prefix
// Problem Link: https://leetcode.com/problems/longest-common-prefix/

#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    // Initialize the common prefix with the first string in the vector
    string commonPrefix = strs[0];
    // Iterate through the strings in the vector starting from index 1
    for (int i = 1; i < strs.size(); i++) {
        // Create a new string to store the updated common prefix
        string newCommonPrefix = "";
        // Iterate through the characters of the current string
        for (int letter = 0; letter < strs[i].length(); letter++) {
            // Check if the current character is within the bounds of the common prefix
            // and if it matches the corresponding character in the common prefix
            if (letter < commonPrefix.length() && commonPrefix[letter] == strs[i][letter])
                // If the characters match, append the character to the new common prefix
                newCommonPrefix += commonPrefix[letter];
    	    else // If there is a mismatch or the character is beyond the bounds of the common prefix,
                break;
        }
        // Update the common prefix with the new common prefix found for the current string
        commonPrefix = newCommonPrefix;
    }
    // Return the final common prefix
    return commonPrefix;
}

