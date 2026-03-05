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
    bool flag = true; 

    int maxHeight(TreeNode *root) {
        if (!root) return 0; 

        int l = maxHeight(root->left); 
        int r = maxHeight(root->right); 
        if (abs(l - r) > 1) {
            flag = false; 
        }

        return 1 + max(l, r); 
    }
public:
    bool isBalanced(TreeNode* root) {
        maxHeight(root); 
        return flag; 
    }
};