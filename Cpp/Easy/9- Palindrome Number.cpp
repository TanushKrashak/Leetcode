
// DIFFICULTY: Easy
// Problem: 9. Palindrome Number
// Problem Link: https://leetcode.com/problems/palindrome-number/

#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x) {
	if (x < 0) // Handle Edge Case
		return false; 
	int temp = x;
	int newX = 0;
	while (temp > 0) {		
		if ((long long int)(newX) * 10 + (temp % 10) >= pow(2, 31))
			return false;
		newX = newX * 10 + (temp % 10);
		temp /= 10;
	}
	if (newX == x)
		return true;
	return false;
}
