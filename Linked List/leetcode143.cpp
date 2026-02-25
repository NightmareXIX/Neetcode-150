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
    bool flag = true; 
    ListNode* root; 

    void recur(ListNode* cur) {
        if (cur == nullptr) 
            return; 

        recur(cur->next); 
        if (flag) {
            if (cur == root or root->next == cur) {
                flag = false; 
                cur->next = nullptr; 
            }
            else {
                cur->next = root->next; 
                root->next = cur; 
                root = cur->next; 
            }
        }
    }
public:
    void reorderList(ListNode* head) {
        root = head; 
        if (head->next != nullptr) 
            recur(head); 
    }
};