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
    int dfs(TreeNode* root, int maxVal) {
        if(root==nullptr) return 0;
        int res=0;
        if(root->val >= maxVal) res = 1;//if node is GoodNode
        maxVal = max(root->val,maxVal);
        int l = dfs(root->left,maxVal);//no.of goodNodes in left
        int r = dfs(root->right,maxVal);//no.of goodNodes in left
        return (res+l+r);//no.of GoodNodes in subtree at root
    }

    int goodNodes(TreeNode* root) {
        int maxVal=root->val;
        return dfs(root,maxVal);
    }
};
