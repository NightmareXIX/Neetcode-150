#include <bits/stdc++.h>
using namespace std; 

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp; 
        mp[NULL] = NULL; 

        Node *cur = head; 
        while (cur != NULL) {
            Node *newNode = new Node(cur->val); 
            mp[cur] = newNode; 
            cur = cur->next; 
        }

        cur = head; 
        while (cur != NULL) {
            mp[cur]->next = mp[cur->next]; 
            mp[cur]->random = mp[cur->random]; 
            cur = cur->next; 
        }
        return mp[head]; 
    }
};