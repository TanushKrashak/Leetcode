
// DIFFICULTY: Medium
// Problem: 50. Pow(x, n)
// Problem Link: https://leetcode.com/problems/powx-n/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void calcPAns(double x, int n, double& ans, double mX, int mN) {
	if (n == 0)
		return;
	if ((long long int)mN * 2 <= n) {
		mN *= 2;
		mX *= mX;
		calcPAns(x, n, ans, mX, mN);
		return;
	}
	ans *= mX;
	calcPAns(x, n - mN, ans, x, 1);
	return;
}

void calcNAns(double x, int n, double& ans, double mX, int mN) {
	if (n == 0)
		return;
	if ((long long int)mN * 2 >= n) {
		mN *= 2;
		mX *= mX;
		calcNAns(x, n, ans, mX, mN);
		return;
	}
	ans *= 1 / mX;
	calcNAns(x, n - mN, ans, x, -1);
	return;
}

double myPow(double x, int n) {
	double ans = 1;
	if (x == 1)
		return x;
	else if (x == -1) {
		if (n % 2 == 0)
			return 1;
		return -1;
	}
	if (n < 0) {
		calcNAns(x, n, ans, x, -1);
	}
	else
		calcPAns(x, n, ans, x, 1);
	return ans;
}
