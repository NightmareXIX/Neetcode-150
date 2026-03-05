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
    int cur = 0, ans; 

    void trav(TreeNode *root, int k) {
        if (!root) return; 
        trav(root->left, k); 
        cur++; 
        if (cur == k) ans = root->val; 
        trav(root->right, k); 
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        trav(root, k); 
        return ans;  
    }
};