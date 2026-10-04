class Solution {
public:
    vector<vector<int>>memo{1000,vector<int>(1000,-1)};
    int dp(int i,int j,string& s,string& t) {
        if(i >= s.size()) {
            if(j >= t.size()) {
                return 1;
            }
            return 0;
        }

        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int ans = 0;
        if(s[i] == t[j]) {
            ans += dp(i+1,j+1,s,t);
        }
        ans += dp(i+1,j,s,t);
        return memo[i][j] = ans;
    }
    
    int numDistinct(string s, string t) {
        if(s.size() < t.size()) return 0;
        return dp(0,0,s,t);
    }
};
