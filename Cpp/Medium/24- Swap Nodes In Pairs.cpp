// DIFFICULTY: Medium
// Problem: 24. Swap Nodes in Pairs
// Problem Link: https://leetcode.com/problems/swap-nodes-in-pairs/

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

ListNode* swapPairs(ListNode* head) {
	ListNode* firstHead = head;
	if (head == nullptr)
		return nullptr;
	ListNode* secondHead = firstHead->next;
	ListNode* previousHead = nullptr;
	while (firstHead != nullptr && secondHead != nullptr) {
		firstHead->next = secondHead->next;
		secondHead->next = firstHead;
		if (previousHead == nullptr) {
			head = secondHead;
			previousHead = head;
		}
		else {
			previousHead->next = secondHead;
		}
		previousHead = firstHead;
		firstHead = firstHead->next;
		if (firstHead == nullptr) {
			return head;
		}
		secondHead = firstHead->next;
	}
	return head;
}
