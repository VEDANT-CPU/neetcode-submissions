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
    bool SameTree(TreeNode* t1, TreeNode* t2) {
        if(t1==nullptr && t2==nullptr) return true;
        if(t1==nullptr && t2!=nullptr) return false;
        if(t2==nullptr && t1!=nullptr) return false;
        if (t1->val != t2->val) return false;

        bool l = SameTree(t1->left, t2->left);
        bool r = SameTree(t1->right, t2->right);
        return (l && r);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == nullptr) return true;
        if(root == nullptr) return false;
        
        if(SameTree(root, subRoot)) return true;
        bool l = isSubtree(root->left, subRoot);
        bool r = isSubtree(root->right, subRoot);
        return (l || r);
    }
};
