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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, val = l1->val + l2->val + carry;
        carry = val / 10; 

        ListNode *node = new ListNode(); 
        ListNode *head = node; 
        node->val = val % 10; 
        l1 = l1->next, l2 = l2->next; 

        while (l1 and l2) {
            ListNode *newNode = new ListNode(); 
            node->next = newNode; 
            node = node->next; 

            val = l1->val + l2->val + carry; 
            carry = val / 10; 
            node->val = val % 10; 
            l1 = l1->next, l2 = l2->next; 
        }

        while (l1) {
            ListNode *newNode = new ListNode(); 
            node->next = newNode; 
            node = node->next; 

            val = l1->val + carry; 
            carry = val / 10; 
            node->val = val % 10; 
            l1 = l1->next; 
        }
        while (l2) {
            ListNode *newNode = new ListNode(); 
            node->next = newNode; 
            node = node->next; 

            val = l2->val + carry; 
            carry = val / 10; 
            node->val = val % 10; 
            l2 = l2->next; 
        }

        while (carry) {
            ListNode *newNode = new ListNode(); 
            node->next = newNode; 
            node = node->next; 
            node->val = carry % 10; 
            carry /= 10; 
        }

        return head; 
    }
};