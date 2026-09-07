#include<cstring>
class Solution {
public:
    vector<vector<int>> choice = {{0,1},{1,0}};
    int memo[101][101];
    int dp(int i,int j,int m,int n) {
        if(i>=m || j>=n) {
            return 0;
        }
        if(i==m-1 && j==n-1) {
            memo[i][j] = 1;
            return 1;
        }

        if(memo[i][j]!=0) {
            return memo[i][j];
        }

        for(const auto& x : choice) {
            memo[i][j] += dp(i+x[0],j+x[1],m,n);
        }
        return memo[i][j];
    }


    int uniquePaths(int m, int n) {
        memset(memo,0,sizeof(memo));
        return dp(0,0,m,n);
    }
};
