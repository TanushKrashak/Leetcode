
// DIFFICULTY: Medium
// Problem: 29. Divide Two Integers
// Problem Link: https://leetcode.com/problems/divide-two-integers/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        // Special case: overflow
        return INT_MAX;
    }
    else if (divisor == 1)
        return dividend;
    bool negative = (dividend < 0) ^ (divisor < 0);
    long long int dvd = llabs(dividend);  // Use long long int to avoid overflow
    long long int dvs = llabs(divisor);   

    int result = 0;
    while (dvd >= dvs) {
        long long int temp = dvs;
        int multiple = 1;
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        dvd -= temp;
        result += multiple;
    }
    return negative ? -result : result;
}
