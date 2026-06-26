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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode * curr = root;
        queue<TreeNode *> q;
        q.push(root);
        //vector<vector<int>>vec;
        while(!q.empty()) {
            int size = q.size();
            vector<int>level;
            for(int i=0; i<size; i++) {
                curr = q.front();
                //level.push_back(curr->val);
                swap(curr->left,curr->right);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                q.pop();
            }
            //vec.push_back(level);
        }

        return root;
    }
};
