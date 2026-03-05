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
    int mx = 0; 
    
    int getMax(TreeNode *root) {
        if (!root) return 0; 

        int l = getMax(root->left); 
        int r = getMax(root->right); 
        mx = max(mx, l + r); 

        return 1 + max(l, r); 
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        getMax(root); 
        return mx; 
    }
};