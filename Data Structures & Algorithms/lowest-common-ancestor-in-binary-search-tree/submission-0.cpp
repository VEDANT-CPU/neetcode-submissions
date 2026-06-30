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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        while(true) {
            if(curr->val<=p->val && curr->val>=q->val) {
                break;
            }
            if(curr->val>=p->val && curr->val<=q->val) {
                break;
            }
            if(curr->val>p->val && curr->val>q->val) {
                curr=curr->left;
            }
            if(curr->val<p->val && curr->val<q->val) {
                curr=curr->right;
            }
        }
        return curr;
    }
};
