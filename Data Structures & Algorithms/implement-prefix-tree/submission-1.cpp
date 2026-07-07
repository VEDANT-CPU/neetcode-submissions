struct Node {
    Node *links[26];
    bool fl=false;
};

class PrefixTree {
private:
    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for(int i=0; i<word.size(); i++) {
            if(cur->links[word[i]-'a']==nullptr) {
                cur->links[word[i]-'a'] = new Node();
            }
            cur = cur->links[word[i]-'a'];
        }
        cur->fl = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(int i=0; i<word.size(); i++) {
            if(!cur) break;
            cur = cur->links[word[i]-'a'];
            if(i==word.size()-1) break;
        }
        if(cur != nullptr && cur->fl) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(int i=0; i<prefix.size(); i++) {
            if(!cur) break;
            cur = cur->links[prefix[i]-'a'];
            if(i==prefix.size()-1) break;
        }
        if(!cur) return false;
        return true;
    }
};
