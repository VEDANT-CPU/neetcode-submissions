/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*>mp;

    Node* cloneGraph(Node* node) {
        if(node==nullptr) return node;
        queue<Node*> q;
        q.push(node);
        Node* start=nullptr;
        Node* temp=nullptr;
        while(!q.empty()) {
            if(mp[q.front()]==nullptr) {
                temp = new Node(q.front()->val);
                mp[q.front()] = temp;
            }
            else temp = mp[q.front()];
            if(mp[node]==temp) start = temp;
            Node* t2 = q.front();
            q.pop();
            for(auto x : t2->neighbors) {
                if(mp[x]==nullptr) {
                    Node* n = new Node(x->val);
                    mp[x] = n;
                    
                    q.push(x);
                }
                temp->neighbors.push_back(mp[x]);
            }
        }
        return start;
    }
};
