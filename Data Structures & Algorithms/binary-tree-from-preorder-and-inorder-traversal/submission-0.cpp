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
    TreeNode* CreateTree(vector<int>& preorder, vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd, unordered_map<int,int>& mp) {
        if(preStart>preEnd || inStart>inEnd) return nullptr;
        TreeNode* node = new TreeNode(preorder[preStart]);
        int mid = mp[preorder[preStart]];
        int leftSize = mid - inStart;
        node->left = CreateTree(preorder,inorder,preStart+1,preStart+leftSize,inStart,mid-1,mp);
        
        node->right = CreateTree(preorder,inorder,preStart+leftSize+1,preEnd,mid+1,inEnd,mp);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        TreeNode* root = CreateTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,mp);
        return root;
    }
};
