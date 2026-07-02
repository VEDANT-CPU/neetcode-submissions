/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool dfs(TreeNode* root, int max_left, int min_right) {
        if(root == nullptr) return true;
        bool res=true;
        if(root->val <= max_left) res=false;
        if(root->val >= min_right) res=false;
        bool l = dfs(root->left, max_left, root->val);
        bool r = dfs(root->right, root->val, min_right);
        return (res && l && r);
    }
    
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};
