
// DIFFICULTY: Medium
// Problem: 17. Letter Combinations of a Phone Number
// Problem Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> letterCombinations(string currentString) {
	vector<vector<string>> letterVec;
	vector<vector<string>> AllLetters = { {"a", "b", "c"}, {"d", "e", "f"},{"g", "h", "i"}, {"j", "k", "l"}
											,{"m", "n", "o"}, {"p", "q", "r", "s"}, {"t", "u", "v"}
											,{"w", "x", "y", "z"} };
	int currentIndex;
	for (int i = 0; i < currentString.size(); i++) {
		stringstream obj;
		obj << currentString[i];
		obj >> currentIndex;
		currentIndex -= 2;
		letterVec.push_back(AllLetters[currentIndex]);
	}
	AllLetters.clear();
	currentString = "";
	vector<string> finalArr = {};
	if (letterVec.size() == 0)
		return finalArr;
	vector<int> indexList(letterVec.size(), 0);
	currentIndex = 0;

	while (true) {
		// Str Len less than Max therefore Add char
		if (currentString.length() != letterVec.size()) {
			currentString += letterVec[currentIndex][indexList[currentIndex]];
			if (currentIndex < letterVec.size() - 1)
				currentIndex++;
			continue;
		}

		//Return Condition
		else if (indexList[0] == letterVec[0].size() - 1 && currentString.length() == letterVec.size()) {
			bool shouldReturn = true;
			for (int i = 1; i < letterVec.size(); i++) {
				if (indexList[i] != letterVec[i].size() - 1) {
					shouldReturn = false;
					break;
				}
			}
			if (shouldReturn == true) {
				finalArr.push_back(currentString);
				break;
			}
		}

		// Changing Indexes
		if (currentString.length() == letterVec.size()) {
			finalArr.push_back(currentString);
			currentString = "";
			int count = 1;
			if (indexList[currentIndex] != letterVec[currentIndex].size() - 1) {
				indexList[currentIndex]++;
				currentIndex = 0;
				continue;
			}
			while (true) {
				if (currentIndex - count >= 0 && indexList[currentIndex - count] != letterVec[currentIndex - count].size() - 1) {
					indexList[currentIndex - count]++;
					currentIndex = currentIndex - count;
					for (int i = currentIndex + 1; i < letterVec.size(); i++) {
						indexList[i] = 0;
					}
					currentIndex = 0;
					break;
				}
				count++;
				if (count == letterVec.size()) {
					indexList[currentIndex]++;
					break;
				}
			}
		}
	}
	return finalArr;
}

