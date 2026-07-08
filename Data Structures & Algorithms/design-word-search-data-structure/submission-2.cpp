struct Node {
    Node* links[26];
    bool fl=false;
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for(int i=0; i<word.size(); i++) {
            int next = word[i] - 'a';
            if(cur->links[next]==nullptr)
                cur->links[next] = new Node();
            cur = cur->links[next];
        }
        cur->fl = true;
    }
    
    bool searchUtil(Node* root, string word) {
        Node *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            char ch = word[i];
            
            if(ch == '.') {
                
                for(int j = 0; j<26; j++) {
                    if(crawler->links[j] != NULL)
                        if(searchUtil(crawler->links[j], word.substr(i+1)))
                            return true;
                }
                
                return false;
                
            } else if (crawler->links[ch-'a'] == NULL) {
                return false;
            }
            
            crawler = crawler->links[ch-'a']; 
        }
        return (crawler != NULL && crawler->fl); 
    }

    bool search(string word) {
        return searchUtil(root, word);
    }
};
