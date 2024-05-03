
// DIFFICULTY: Easy
// Problem: 21. Merge Two Sorted Lists
// Problem Link: https://leetcode.com/problems/merge-two-sorted-lists/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Struct used by leetcode
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	// If either list empty, can't merge so return the other
	if (list1 == nullptr)
		return list2;
	else if (list2 == nullptr)
		return list1;

	ListNode* mainHead = list1;
	if (list1->val > list2->val) {
		mainHead = list2;
		bool head1 = false;
		list2 = list2->next;
	}
	else {
		list1 = list1->next;
	}
	ListNode* tempPointer = mainHead;
	while (list1 != nullptr && list2 != nullptr) {
		ListNode* temp;
		if (list1->val > list2->val) {
			tempPointer->next = list2;
			temp = list2->next;
			list2->next = list1;
			list2 = temp;
			tempPointer = tempPointer->next;
		}
		else {
			tempPointer->next = list1;
			temp = list1->next;
			list1->next = list2;
			list1 = temp;
			tempPointer = tempPointer->next;
		}
	}
	while (list1 != nullptr) {
		tempPointer->next = list1;
		list1 = list1->next;
		tempPointer = tempPointer->next;
	}
	while (list2 != nullptr) {
		tempPointer->next = list2;
		list2 = list2->next;
		tempPointer = tempPointer->next;
	}
	return mainHead;
}
