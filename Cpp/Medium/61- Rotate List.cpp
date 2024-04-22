
// DIFFICULTY: Medium
// Problem: 61. Rotate List
// Problem Link: https://leetcode.com/problems/rotate-list/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* rotateRight(ListNode* head, int k) {
	if (head == nullptr)
		return nullptr;
	int size = 0;
	ListNode* temp = head;
	while (temp != nullptr) {
		size++;
		temp = temp->next;
	}
	k = k % size;
	for (int i = 0; i < k; i++) {
		ListNode* temp = head;
		ListNode* prev = temp;
		while (temp->next != nullptr) {
			prev = temp;
			temp = temp->next;
		}
		temp->next = head;
		prev->next = nullptr;
		head = temp;
	}
	return head;
}
