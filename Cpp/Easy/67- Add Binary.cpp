
// DIFFICULTY: Easy	
// Problem: 67. Add Binary
// Problem Link: https://leetcode.com/problems/add-binary/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

string addBinary(string a, string b) {
	string c = "";
	int sA = a.size() - 1;
	int sB = b.size() - 1;
	int count = 0;
	while(sA - count >= 0 && sB - count >= 0) {
		c.insert(0, to_string(a[sA - count] - '0' + b[sB - count] - '0'));
		count++;
	}
	while(sA - count >= 0) {
		c.insert(0, to_string(a[sA - count] - '0'));
		count++;
	}
	while(sB - count >= 0) {
		c.insert(0, to_string(b[sB - count] - '0'));
		count++;
	}
	count = 0;
	int sC = c.size() - 1;
	while(sC - count >= 0) {
		if(c[sC - count] >= '2') {
			c[sC - count] = char(c[sC - count] - ('2' - '0'));
			if(sC - count > 0) {
				c[sC - count - 1] = char(c[sC - count - 1] + '1' - '0');
			}
			else {
				c.insert(0, "1");
			}
		}
		count++;
	}
	return c;
}
