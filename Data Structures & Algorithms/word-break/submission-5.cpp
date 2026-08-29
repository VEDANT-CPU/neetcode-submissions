class Solution {
public:
    unordered_set<string> MySet;
    unordered_map<int,bool>memo;
    bool dfs(int index,string s,int t) {
        if(memo.contains(index)) {
            return memo[index];
        }

        if(index == s.size()) return true;
        for(int j=index; j<=min((int)s.size(),index+t)-1;j++) {
            if(MySet.contains(s.substr(index,j-index+1))) {
                if(dfs(j+1,s,t)) {
                    memo[index] = true;
                    return true;
                }
            }
        }
        memo[index] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int t=0;
        for(int i=0; i<wordDict.size(); i++) {
            MySet.insert(wordDict[i]);
            t = max(t,(int)wordDict[i].size());
        }
        return dfs(0,s,t);
    }
};
