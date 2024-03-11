
// DIFFICULTY: Medium
// Problem: 19. Remove Nth Node From End of List
// Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* currentVal = head;
	int index = 0;
	while (currentVal->next != nullptr) {
		index++;
		currentVal = currentVal->next;
	}
	int valToRemove = (index + 1) - n;
	n = index;
	index = 0;
	ListNode* previous = head;
	currentVal = head;
	if (valToRemove == 0) {
		if (head->next != nullptr) {
			head = head->next;
			return head;
		}
		return nullptr;
	}
	while (currentVal->next != nullptr) {
		if (index == valToRemove) {
			previous->next = currentVal->next;
			break;
		}
		index++;
		previous = currentVal;
		currentVal = currentVal->next;
	}
	if (index == n) {
		previous->next = nullptr;
	}
	return head;
}

