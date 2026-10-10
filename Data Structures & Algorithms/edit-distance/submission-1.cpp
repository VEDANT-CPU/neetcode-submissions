class Solution {
public:
    vector<vector<int>>memo{100,vector<int>(100,-1)};
    
    int dp(int i,int j,string& word1,string& word2) {
        if(i == word1.size()) {
            return (word2.size() - j);
        }
        if(j == word2.size()) {
            return (word1.size() - i);
        }
        if(memo[i][j] != -1) return memo[i][j];

        if(word1[i] == word2[j]) {
            return memo[i][j]=dp(i+1,j+1,word1,word2);
        }
//we won't actually insert, delete or replace we assume we did and move to next sub problem
        return memo[i][j] = 1 + min(dp(i,j+1,word1,word2),min(dp(i+1,j,word1,word2),dp(i+1,j+1,word1,word2)));
    }
    
    int minDistance(string word1, string word2) {
        return dp(0,0,word1,word2);
    }
};
