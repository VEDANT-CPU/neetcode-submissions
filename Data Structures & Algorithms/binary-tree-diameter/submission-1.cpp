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
    int max_dia=0;
    int TreeDepth(TreeNode * root) {
        if(root == nullptr) return 0;
        int l=TreeDepth(root->left);
        int r=TreeDepth(root->right);
        max_dia = max(max_dia, l+r);
        return 1 + max(l,r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        TreeDepth(root);
        return max_dia;
    }
};
