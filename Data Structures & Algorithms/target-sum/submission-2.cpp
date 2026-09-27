class Solution {
public:
    vector<vector<int>>memo{20,vector<int>(2001,-1)};
    
    int dp(int i,int target,vector<int>& nums) {
        if(i == (int)nums.size() && target==0) {
            return 1;
        }
        if(i == (int)nums.size() && target!=0) {
            return 0;
        }
        int t_target = 0;
        if(target<0) {
            t_target = 1000 + (target%1000)*(-1);
        }else {
            t_target = target;
        }
        if(memo[i][t_target] != -1) {
            return memo[i][t_target];
        }

        //choose to add or subtract element
        return memo[i][t_target]=dp(i+1,target-nums[i],nums) + dp(i+1,target+nums[i],nums);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return dp(0,target,nums);
    }
};
