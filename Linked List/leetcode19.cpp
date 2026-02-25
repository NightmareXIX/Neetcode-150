
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private: 
    int recur(ListNode *prev, ListNode *cur, int n) {
        if (cur == nullptr)
            return 0; 
    
        int val = 1 + recur(cur, cur->next, n); 
        if (val == n) {
            prev->next = cur->next; 
        }
        return val; 
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int val = 1 + recur(head, head->next, n); 
        if (val == n)
            head = head->next; 
        return head; 
    }
};