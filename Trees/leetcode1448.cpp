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
    int good = 0; 

    void dfs(TreeNode *root, int mx) {
        if (!root) return; 
        if (root->val >= mx) good++; 

        dfs(root->left, max(mx, root->val)); 
        dfs(root->right, max(mx, root->val)); 
    }
public:
    int goodNodes(TreeNode* root) {
        int mx = -1e5; 
        dfs(root, mx); 
        return good; 
    }
};