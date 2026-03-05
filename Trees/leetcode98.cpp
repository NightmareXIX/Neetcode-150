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
    #define ll long long
    bool flag = true; 

    void dfs(TreeNode *root, ll l, ll r) {
        if (!root) return; 
        if (!flag or (root->val <= l or root->val >= r)) {
            flag = false; return; 
        }

        dfs(root->left, l, min(r, (ll)root->val)); 
        dfs(root->right, max(l, (ll)root->val), r); 
    }
public:
    bool isValidBST(TreeNode* root) {
        ll l = LLONG_MIN, r = LLONG_MAX; 
        dfs(root, l, r); 
        return flag; 
    }
};