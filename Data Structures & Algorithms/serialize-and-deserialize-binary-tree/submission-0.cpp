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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if (!root) return "";
        
        std::string result = "";
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (!curr) {
                result += "#,";
            } else {
                result += std::to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        // Remove the trailing comma
        if (!result.empty()) result.pop_back();
        return result;
    }

    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        std::stringstream ss(data);
        std::string str;
        
        // Read the root node value
        std::getline(ss, str, ',');
        if (str == "#") return nullptr;
        
        TreeNode* root = new TreeNode(std::stoi(str));
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* parent = q.front();
            q.pop();
            
            // 1. Process the Left Child
            if (std::getline(ss, str, ',')) {
                if (str != "#") {
                    TreeNode* leftChild = new TreeNode(std::stoi(str));
                    parent->left = leftChild;
                    q.push(leftChild);
                }
            }
            
            // 2. Process the Right Child
            if (std::getline(ss, str, ',')) {
                if (str != "#") {
                    TreeNode* rightChild = new TreeNode(std::stoi(str));
                    parent->right = rightChild;
                    q.push(rightChild);
                }
            }
        }
        
        return root;
    }
};
