#include <bits/stdc++.h>
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private: 
    ListNode *reverseList(ListNode *cur, ListNode *des) {
        if (cur == des)
            return cur; 

        reverseList(cur->next, des)->next = cur; 
        return cur; 
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head, *prev = nullptr; 
        while (cur) {
            int cnt = 1; 
            ListNode *des = cur; 
            while (des and cnt < k) {
                des = des->next; 
                cnt++; 
            }
            if (!des) {
                if (prev) prev->next = cur, prev = nullptr; 
                break; 
            }

            ListNode *nextNode = des->next; 
            reverseList(cur, des)->next; 
            if (prev) prev->next = des; 

            if (cur == head) head = des; 
            prev = cur; 
            cur = nextNode; 
        }
        if (prev) prev->next = nullptr; 

        return head; 
    }
};