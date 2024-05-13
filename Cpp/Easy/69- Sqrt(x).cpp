
// DIFFICULTY: Easy	
// Problem: 69. Sqrt(x)
// Problem Link: https://leetcode.com/problems/sqrtx/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int mySqrt(int x) {
	int sqrt = 0;
	for(int i = 1; i <= x; i++) {
		if((long long int)i * i <= x)
			sqrt = i;
		else
			break;
	}
	return sqrt;
}
