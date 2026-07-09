class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool endOfWord;
        string word;

        TrieNode() {
            endOfWord = false;
            word = "";
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    TrieNode* root = new TrieNode();
    vector<string> result;

    int rows, cols;
    vector<pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    void insert(string& word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr)
                curr->children[idx] = new TrieNode();

            curr = curr->children[idx];
        }

        curr->endOfWord = true;
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            return;

        char ch = board[i][j];

        if (ch == '#')
            return;

        TrieNode* next = node->children[ch - 'a'];

        if (next == nullptr)
            return;

        if (next->endOfWord) {
            result.push_back(next->word);
            next->endOfWord = false;      // avoid duplicates
        }

        board[i][j] = '#';

        for (auto& dir : directions) {
            dfs(board, i + dir.first, j + dir.second, next);
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = board[0].size();

        for (string& word : words)
            insert(word);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (root->children[board[i][j] - 'a'] != nullptr)
                    dfs(board, i, j, root);
            }
        }

        return result;
    }
};