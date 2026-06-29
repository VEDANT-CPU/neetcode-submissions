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
    int res = true;
    
    int TreeHeight(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = TreeHeight(root->left);
        int right = TreeHeight(root->right);
        if(abs(left-right)>1) res = false;
        return 1 + max(left,right);
    }
    
    bool isBalanced(TreeNode* root) {
        TreeHeight(root);
        return res;
    }
};
