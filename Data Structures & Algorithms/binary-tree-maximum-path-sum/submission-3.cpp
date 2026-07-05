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
    int maxSum=0;
    int PathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int l=PathSum(root->left);
        if(l<0) l=0;
        int r=PathSum(root->right);
        if(r<0) r=0;
        maxSum = max(maxSum, root->val + l + r);
        return (root->val + max(l,r));
    }

    int maxPathSum(TreeNode* root) {
        maxSum = root->val;
        int dummy = PathSum(root);
        return maxSum;
    }
};
