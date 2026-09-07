#include<cstring>
class Solution {
public:
    int memo[1001][1001];
    int dp(int i,int j,string& text1,string& text2) {
        if(i==text1.size() || j==text2.size()) {
            memo[i][j] = 0;
            return memo[i][j];
        }

        if(memo[i][j] != -1) {
            return memo[i][j];
        }

        if(text1[i]==text2[j]) {
            memo[i][j] = dp(i+1,j+1,text1,text2)+1;
        }else {
            memo[i][j] = max(dp(i+1,j,text1,text2),dp(i,j+1,text1,text2));
        }
        return memo[i][j];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(memo,-1,sizeof(memo));
        return dp(0,0,text1,text2);
    }
};
