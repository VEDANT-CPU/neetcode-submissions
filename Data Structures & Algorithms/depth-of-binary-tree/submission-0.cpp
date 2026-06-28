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
    bool isLeaf(TreeNode* node) {
        if(node->left==nullptr && node->right==nullptr) {
            return true;
        }
        return false;
    }
    int NodeHeight(TreeNode* node) {
        if(node == nullptr) return 0;
        int left_ht = NodeHeight(node->left);
        int right_ht = NodeHeight(node->right);
        int ht = 1+max(left_ht, right_ht);
        return ht;
    }
    
    int maxDepth(TreeNode* root) {
        int max_ht = NodeHeight(root);
        return max_ht;
    }
};
