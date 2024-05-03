
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

	// Determine the head of the merged list
	ListNode* mainHead = list1;
	if (list1->val > list2->val) {
		mainHead = list2; // Set the head of the merged list to the smaller value node
		list2 = list2->next; // Move to the next node in list2
	}
	else {
		list1 = list1->next; // Move to the next node in list1
	}

	// Merge the two lists
	ListNode* tempPointer = mainHead;
	while (list1 != nullptr && list2 != nullptr) {
		ListNode* temp;
		if (list1->val > list2->val) {
			// Insert list2 node into merged list
			tempPointer->next = list2; // Set the next node of the current node to list2 node
			temp = list2->next; // Save the next node of list2
			list2->next = list1; // Connect list2 node to list1 node
			list2 = temp; // Move to the next node in list2
			tempPointer = tempPointer->next; // Move to the next node in the merged list
		}
		else {
			// Insert list1 node into merged list
			tempPointer->next = list1; // Set the next node of the current node to list1 node
			temp = list1->next; // Save the next node of list1
			list1->next = list2; // Connect list1 node to list2 node
			list1 = temp; // Move to the next node in list1
			tempPointer = tempPointer->next; // Move to the next node in the merged list
		}
	}

	// Append remaining nodes from list1 and list2 if any
	while (list1 != nullptr) {
		tempPointer->next = list1; // Append remaining nodes from list1
		list1 = list1->next; // Move to the next node in list1
		tempPointer = tempPointer->next; // Move to the next node in the merged list
	}
	while (list2 != nullptr) {
		tempPointer->next = list2; // Append remaining nodes from list2
		list2 = list2->next; // Move to the next node in list2
		tempPointer = tempPointer->next; // Move to the next node in the merged list
	}
	return mainHead;
}
