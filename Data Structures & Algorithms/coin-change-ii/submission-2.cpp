class Solution {
public:
    //int cnt=0;
    vector<vector<int>>memo{100,vector<int>(5001,-1)};
    int dp(int i,int target,vector<int>& coins) {
        if(i >= (int)coins.size() || target<=0) {
            if(target==0) return 1;
            return 0;
        }

        if(memo[i][target] != -1) {
            return memo[i][target];
        }

        return memo[i][target] = dp(i,target-coins[i],coins) + dp(i+1,target,coins);
        //add the coin atleast once
        //memo[i][target] += dp(i,target-coins[i],coins);

        //if you don't pick the coin
        //memo[i][target] += dp(i+1,target,coins);
    }
    
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        return dp(0,amount,coins);
    }
};
