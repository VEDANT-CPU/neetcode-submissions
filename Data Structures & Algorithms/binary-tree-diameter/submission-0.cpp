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
    int TreeDepth(TreeNode * root) {
        if(root == nullptr) return 0;
        int l=TreeDepth(root->left);
        int r=TreeDepth(root->right);
        return 1 + max(l,r);
    }
    
    int max_dia=0;

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int l = diameterOfBinaryTree(root->left);
        int r = diameterOfBinaryTree(root->right);
        max_dia = max(max_dia, max(l,r));

        int left_depth = TreeDepth(root->left);
        int right_depth = TreeDepth(root->right);
        max_dia = max(left_depth + right_depth, max_dia);
        return max_dia;
    }
};
