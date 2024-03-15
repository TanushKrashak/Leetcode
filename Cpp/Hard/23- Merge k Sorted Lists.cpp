
// DIFFICULTY: Hard
// Problem: 23. Merge k Sorted Lists
// Problem Link: https://leetcode.com/problems/merge-k-sorted-lists/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
	int numOfLists = lists.size();
	ListNode* mainHead = nullptr;
	ListNode* currLocation = nullptr;
	while (true) {
		vector<int> values = {};
		for (int i = 0; i < numOfLists; i++) {
			if (lists[i] != nullptr)
				values.push_back(lists[i]->val);
		}
		if (values.size() > 0) {
			int indexForLowest = 0;
			int lowest = int(values[0]);
			for (int i = 1; i < values.size(); i++) {
				if (values[i] < lowest) {
					lowest = values[i];
					indexForLowest = i;
				}
			}
			for (int i = 0; i < numOfLists; i++) {
				if (lists[i] == nullptr) {
					continue;
				}
				else if (indexForLowest == 0) {
					if (mainHead == nullptr) {
						mainHead = lists[i];
						currLocation = mainHead;
					}
					else {
						currLocation->next = lists[i];
						currLocation = currLocation->next;
					}
					lists[i] = lists[i]->next;
					break;
				}
				else
					indexForLowest--;

			}
		}
		// return condition        
		bool stopLoop = true;
		for (int i = 0; i < numOfLists; i++) {
			if (lists[i] != nullptr) {
				stopLoop = false;
				break;
			}
		}
		if (stopLoop == true)
			break;
	}
	return mainHead;
}

