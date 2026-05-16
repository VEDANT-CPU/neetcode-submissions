class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap<int,int>mp;
        vector<int>res(2);
        for(int i=0; i<nums.size(); i++) {
            mp.insert({nums[i],i});
        }
        for(auto it : mp) {
            if(mp.find(target-it.first)!=mp.end()) {
                int r1=it.second;
                int r2=mp.find(target-(it.first))->second;
                if (r2 != r1) {
                    res[0]=r1;
                    res[1]=r2;
                    break;
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
