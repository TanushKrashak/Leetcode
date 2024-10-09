
// DIFFICULTY: Easy	
// Problem: 70. Climbing Stairs
// Problem Link: https://leetcode.com/problems/climbing-stairs/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;


int climbStairs(int n) {
    if (n==0) 
        return 0;
    int a =0, b=1, c = 1;
    for (int i =0; i<n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
