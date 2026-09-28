class Solution {
public:
    vector<vector<int>>memo{100,vector<int>(100,-1)};
    
    bool dp(int i,int j,string s1,string s2,string s3) {
        if(i+j == (int)s3.size()) {
            return true;
        }
        if((j<(int)s2.size() && s2[j]!=s3[i+j]) && (i<(int)s1.size() && s1[i]!=s3[i+j])) {
            return false;
        }
        if(memo[i][j] != -1) return memo[i][j];
bool a=false;
bool b=false;
        if(i<(int)s1.size() && s1[i]==s3[i+j]) {
            a = dp(i+1,j,s1,s2,s3);
        }

        if(j<(int)s2.size() && s2[j]==s3[i+j]) {
            b = dp(i,j+1,s1,s2,s3);
        }
        return memo[i][j] = (a || b);
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if(n+m != (int)s3.size()) return false;
        return dp(0,0,s1,s2,s3);
    }
};
