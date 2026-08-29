class Solution {
public:
    unordered_map<int,bool>memo;
    bool dp(int index,string s,vector<string>& wordDict) {
        if(index == s.size()) {
            return true;
        }

        if(memo.contains(index)) return memo[index];

        for(string& w : wordDict) {
            if(index+w.size() <= s.size() && w==s.substr(index,w.size())) {
                if(dp(index+w.size(),s,wordDict)) {
                    memo[index] = true;
                    return true;
                }
            }
        }
        memo[index] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return dp(0,s,wordDict);
    }
};
