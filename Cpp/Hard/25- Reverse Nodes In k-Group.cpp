
// DIFFICULTY: Hard
// Problem: 25. Reverse Nodes in k-Group
// Problem Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

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

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* startRevList = head;
    if (k < 2)
        return head;
    ListNode* previousHead = nullptr;
    ListNode* nextHead = nullptr;
    while (true) {
        int count = 0;
        vector<ListNode*> pointerList = {};
        ListNode* endRevList = startRevList;
        while (endRevList != nullptr) {
            pointerList.push_back(endRevList);
            count++;
            if (count == k)
                break;
            endRevList = endRevList->next;
        }
        if (count != k)
            return head;
        nextHead = endRevList->next;
        if (previousHead == nullptr) {
            head = endRevList;
            previousHead = startRevList;
        }
        else {
            previousHead->next = endRevList;
            previousHead = startRevList;
        }
        for (int i = pointerList.size() - 2; i >= 0; i--) {
            endRevList->next = pointerList[i];
            endRevList = endRevList->next;
        }
        startRevList->next = nextHead;
        startRevList = nextHead;
    }
    return head;
}


