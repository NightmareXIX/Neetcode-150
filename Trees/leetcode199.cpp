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
    vector<int> ans; 

    void dfs(TreeNode *root, int dis) {
        if (!root) return; 
        if (dis == ans.size()) ans.push_back(0); 
        ans[dis] = root->val; 

        dfs(root->left, dis + 1); 
        dfs(root->right, dis + 1); 
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0); 
        return ans; 
    }
};