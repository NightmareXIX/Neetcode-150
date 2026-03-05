#include <bits/stdc++.h>
using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private: 
    bool have = false; 
    int h = 0; 

    int maxHeight(TreeNode *root) {
        if (!root) return 0; 
        return 1 + max(maxHeight(root->left), maxHeight(root->right)); 
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p and !q) return true; 
        if (!p or !q) return false; 

        bool flag = (p->val == q->val); 
        flag &= isSameTree(p->left, q->left); 
        flag &= isSameTree(p->right, q->right);
        
        return flag; 
    }

    int dfs(TreeNode *root, TreeNode *subRoot) {
        if (!root) return 0; 

        int cur = 1 + max(dfs(root->left, subRoot), dfs(root->right, subRoot)); 
        if (cur == h) {
            have |= isSameTree(root, subRoot); 
        }
        return cur; 
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        h = maxHeight(subRoot); 
        dfs(root, subRoot); 
        return have; 
    }
};