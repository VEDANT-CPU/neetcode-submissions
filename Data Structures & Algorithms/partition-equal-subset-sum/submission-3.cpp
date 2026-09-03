#include <cstring>

class Solution {
public:
    int memo[101][5001];
    
    int dp(int i,vector<int>& nums,int W) {
        //this i is one based indexing
        if(i==0 || W==0) {
            return 0;//this state is out of bounds
            //no element there so return 0
        }

        if(memo[i][W] != -1) {
            return memo[i][W];
        }

        if(nums[i] <= W) {
            return memo[i][W] = max(nums[i]+dp(i-1,nums,W-nums[i]), dp(i-1,nums,W));
        }else {
            return memo[i][W] = dp(i-1,nums,W);
        }
    }
    
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        std::memset(memo,-1,sizeof(memo));
        vector<int> nums2(nums.size()+1);
        nums2[0] = -1;
        for(int i=1; i<=nums.size(); i++) {
            nums2[i] = nums[i-1];
        }
        for(auto x : nums) {
            total_sum += x;
        }
        if(total_sum % 2 == 1) {
            return false;
        }
        int half_sum = total_sum / 2;
        int n = nums.size();
        if(dp(n,nums2,half_sum) == total_sum/2)
            return true;
        return false;
    }
};
