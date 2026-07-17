class Node {
public:   
    Node* links[52];
    bool flag=false;
//Don't forget to initialize 
    Node() {
        flag = false;
        for(int i = 0; i < 52; i++)
            links[i] = nullptr;
    }
};

class Tries {
public:
    Node* root;

    Tries() {
        root = new Node();
    }
    void insert(string word) {
        Node* cur = root;
        for(int i=0; i<word.size(); i++) {
            if(isupper(static_cast<unsigned char>(word[i]))) {
                if(cur->links[(word[i]-'A')+26]==nullptr) {
                    cur->links[(word[i]-'A')+26] = new Node();
                }
                cur = cur->links[(word[i]-'A')+26];
            }else {
                if(cur->links[word[i]-'a']==nullptr) {
                    cur->links[word[i]-'a'] = new Node();
                }
                cur = cur->links[word[i]-'a'];
            }
        }
        cur->flag = true;
    }

    
};

class Solution {
public:
    bool ans = false;
    
    vector<pair<int,int>> directions = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    //Run DFS on a matrix algorithm
    void backtrack(vector<vector<char>>& board, int i, int j, Node* node) {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) {
            return;
        }
        if(ans) return;

        char ch = board[i][j];
        
        if(ch == '#') return;
        board[i][j] = '#';
        Node* next = nullptr;
        if(islower(static_cast<unsigned char>(ch))) {
            next = node->links[ch-'a'];
        }else {
            next = node->links[(ch-'A')+26];
        }
        
        if(next == nullptr) {board[i][j]=ch; return;}

        if(next->flag == true) {
            ans = true;
            next->flag = false;
            return;
        }
        for(auto& d : directions) {
            backtrack(board,i+d.first,j+d.second,next);
        }

        board[i][j] = ch;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        Tries* Mytries = new Tries();
        
        
        Mytries->insert(word);
        Node* root = Mytries->root;
        int rows = board.size();
        int cols = board[0].size();
        

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                backtrack(board, i, j, root);
            }
        }
        
        return ans;
    }
};
