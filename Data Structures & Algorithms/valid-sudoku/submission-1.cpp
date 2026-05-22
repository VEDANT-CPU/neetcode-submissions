class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int j=0; j<9; j++) {
            
            unordered_multiset<int>hash_set;
            for(int i=0; i<9; i++) {
                if(board[j][i] != '.')
                hash_set.insert(board[j][i]);
            }
            for(int x : hash_set) {
                if(hash_set.count(x) > 1) return false;
            }
        }

        for(int j=0; j<9; j++) {
            
            unordered_multiset<int>hash_set;
            for(int i=0; i<9; i++) {
                if(board[i][j] != '.')
                hash_set.insert(board[i][j]);
            }
            for(int x : hash_set) {
                if(hash_set.count(x) > 1) return false;
            }
        }
        vector<unordered_multiset<int>>a(9);
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] != '.')
                a[(i/3)*3 + j/3].insert(board[i][j]);
            }
        }
        for(int i=0; i<9; i++) {
            for(int x : a[i]) {
                if(a[i].count(x) > 1) return false;
            }
        }

        return true;
    }
};
