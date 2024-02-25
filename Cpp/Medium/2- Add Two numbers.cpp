// DIFFICULTY: Medium
// Problem: 2. Add Two Numbers
// Problem Link: https://leetcode.com/problems/add-two-numbers

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	vector<int> newList1;
	vector<int> newList2;
	ListNode* nextPtr = l1->next;
	newList1.push_back(l1->val);
	while (nextPtr != nullptr) {
		newList1.push_back(nextPtr->val);
		nextPtr = nextPtr->next;
	}
	nextPtr = l2->next;
	newList2.push_back(l2->val);
	while (nextPtr != nullptr) {
		newList2.push_back(nextPtr->val);
		nextPtr = nextPtr->next;
	}

	reverse(newList1.begin(), newList1.end());
	reverse(newList2.begin(), newList2.end());

	int list1Index = newList1.size() - 1;
	int list2Index = newList2.size() - 1;
	while (list1Index >= 0 && list2Index >= 0) {
		newList1[list1Index] += newList2[list2Index];
		if (newList1[list1Index] >= 10) {
			newList1[list1Index] -= 10;
			if (list1Index - 1 >= 0) {
				newList1[list1Index - 1] += 1;
				int temp = 1;
				while (list1Index - temp >= 0 && newList1[list1Index - temp] >= 10) {
					newList1[list1Index - temp] -= 10;
					temp++;
					if (list1Index - temp >= 0)
						newList1[list1Index - temp] += 1;
					else {
						newList1.insert(newList1.begin(), 1);
						list1Index++;
					}
				}
			}
			else {
				newList1.insert(newList1.begin(), 1);
				list1Index++;
			}
		}
		list1Index--;
		list2Index--;
	}
	while (list2Index >= 0) {
		newList1.insert(newList1.begin(), newList2[list2Index]);
		list2Index--;
	}
	nextPtr = new ListNode(newList1[0], nullptr);
	for (int i = 1; i < newList1.size(); i++) {
		ListNode* tempPtr = new ListNode(newList1[i], nextPtr);
		nextPtr = tempPtr;
	}
	return nextPtr;
}
