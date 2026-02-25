#include <bits/stdc++.h>
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct CmpByVal {
    bool operator() (const ListNode* a, const ListNode* b) const {
        if (a->val != b->val) return a->val < b->val; 
        return a < b; 
    }
};

class Solution {
private: 
    set<ListNode*, CmpByVal> st; 

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto it : lists) {
            if (it)
                st.insert(it); 
        }

        ListNode *head = nullptr, *cur = head; 
        while (!st.empty()) {
            ListNode* best = *st.begin(); st.erase(st.begin()); 
            if (!cur) {
                head = cur = best; 
            }
            else {
                cur->next = best; cur = cur->next; 
            }

            if (best->next)
                st.insert(best->next); 
        }

        if (cur) cur->next = nullptr; 
        return head; 
    }
};