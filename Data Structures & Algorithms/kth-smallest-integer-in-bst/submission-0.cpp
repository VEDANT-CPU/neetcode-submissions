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
    priority_queue<int> pq;

    void dfs(TreeNode* root, int k) {
        if(root==nullptr) return;
        if(pq.size()<k) pq.push(root->val);
        else if(pq.size()==k) {
            if(root->val<pq.top()) {
                pq.pop();
                pq.push(root->val);
            }
        }
        dfs(root->left,k);
        dfs(root->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return pq.top();
    }
};
