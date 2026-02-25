#include <bits/stdc++.h>
using namespace std; 


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        int inf = 1e6; 
        while (head != nullptr) {
            if (head->val == inf)
                return true; 
            head->val = inf; 
            head = head->next; 
        }
        return false; 
    }
};