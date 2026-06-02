class Solution {
public:
    /*bool contains_trip(vector<vector<int>>b, vector<int> a) {
        sort(a.begin(),a.end());
        for(auto x : b) {
            sort(x.begin(), x.end());
            if (x == a) return true;
        }
        return false;
    }*/
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-2; i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int j= i+1;
            int k=nums.size()-1;
            int sum;
            while(j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(nums[j-1] == nums[j] && j < k) j++;
                }else if(sum < 0) j++;
                else k--;
            }
        }
        
        return res;
    }
};
