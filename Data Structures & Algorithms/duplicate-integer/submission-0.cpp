class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(int x : nums) {
            mp[x].push_back(x);
        }
        for(int y : nums) {
            if(mp[y].size() > 1) return true;
        }
        return false;
    }
};