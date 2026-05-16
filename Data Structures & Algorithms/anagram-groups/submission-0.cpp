class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        for(string x : strs) {
            string y=x;
            sort(y.begin(),y.end());
            mpp[y]={};
        }
        for(string x : strs) {
            string y=x;
            sort(y.begin(),y.end());
            mpp[y].push_back(x);
        }
        vector<vector<string>>res;
        for(auto it : mpp) {
            res.push_back(it.second);
        }
        return res;
    }
};
