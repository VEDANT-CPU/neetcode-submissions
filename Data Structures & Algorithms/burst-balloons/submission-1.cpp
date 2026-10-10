class Solution {
public:
    vector<vector<int>>memo{302,vector<int>(302,-1)};
    int dp(int l,int r,vector<int>& nums) {
        if(l > r) return 0;
        if(memo[l][r] != -1) return memo[l][r];
        
        int coins = 0;
        for(int i=l; i<=r; i++) {
            int temp = nums[l-1]*nums[i]*nums[r+1] + dp(l,i-1,nums) + dp(i+1,r,nums);
            coins = max(coins,temp);
        }
        return memo[l][r] = coins;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        return dp(1,nums.size()-2,nums);
    }
};
