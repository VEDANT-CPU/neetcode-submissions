class Solution {
public:
    bool contains_trip(vector<vector<int>>b, vector<int> a) {
        sort(a.begin(),a.end());
        for(auto x : b) {
            sort(x.begin(), x.end());
            if (x == a) return true;
        }
        return false;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-2; i++) {
            int j=(i != 0) ? 0 : 1;
            int k=nums.size()-1;
            int sum;
            while(j < k) {
                if(j != i && k != i) {
                    sum = nums[i]+nums[j]+nums[k];
                    if(sum == 0) {
                        if(!contains_trip(res, {nums[i],nums[j],nums[k]}))
                            res.push_back({nums[i],nums[j],nums[k]});
                        j++;
                    }
                    else if(sum < 0) j++;
                    else k--;
                }else j++;
            }
        }
        
        return res;
    }
};
