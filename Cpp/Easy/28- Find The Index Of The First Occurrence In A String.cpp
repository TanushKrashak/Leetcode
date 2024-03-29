
// DIFFICULTY: Easy
// Problem: 28. Find the Index of the First Occurrence in a String
// Problem Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int strStr(string haystack, string needle) {
    int haySize = haystack.size();
    int needleSize = needle.size();
    for (int i = 0; i <= haySize - needleSize; i++) {
        if (haystack[i] == needle[0]) {
            int count = 1;
            int newI = i + 1;
            bool stopLoop = true;
            while (count < needleSize) {
                if (needle[count] == haystack[newI]) {
                    count++;
                    newI++;
                }
                else {
                    stopLoop = false;
                    newI--;
                    break;
                }
            }
            if (stopLoop == true)
                return i;
        }
    }
    return -1;
}

// Alternative
//int strStr(string haystack, string needle) {
//    return haystack.find(needle);
//}



