#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, val; 
    Node *prev, *next; 
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
}; 

class LRUCache { 
private: 
    int cap, sz; 
    unordered_map<int, Node*> mp; 
    Node *head, *tail; 
    
    void update_pos(int key) {
        Node *cur = mp[key]; 
        if (cur != tail) {
            if (cur == head) {
                head = head->next; 
                head->prev = nullptr; 
            }
            else {
                cur->prev->next = cur->next; 
                cur->next->prev = cur->prev; 
            }
    
            cur->prev = tail; 
            cur->next = nullptr; 
            tail->next = cur; 
            tail = tail->next; 
        }
    }
    
    void addNode(int key, int value) {
        Node *newNode = new Node(key, value); 
        mp[key] = newNode; 
        newNode->prev = tail; 
        newNode->next = nullptr; 
    
        tail->next = newNode; 
        tail = tail->next;
    }

public:
    LRUCache(int capacity) {
        sz = 0, cap = capacity; 
        head = tail = nullptr; 
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            update_pos(key); 
            return tail->val; 
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            update_pos(key); 
            tail->val = value; 
        }
        else if (!sz) {
            head = tail = new Node(key, value); 
            mp[key] = head; sz++; 
        }
        else if (sz < cap) {
            addNode(key, value); 
            sz++; 
        }
        else {
            addNode(key, value); 
            int k = head->key; 
            mp.erase(mp.find(k)); 
            head = head->next; 
            head->prev = nullptr; 
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */