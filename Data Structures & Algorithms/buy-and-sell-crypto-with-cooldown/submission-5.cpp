class Solution {
public:
    vector<vector<int>> memo{5000,vector<int>(2, -1)};
    
    int dp(int i, int holding, vector<int>& prices) {
        if(i>=(int)prices.size()) {
            return 0;
        }

        if(memo[i][holding] != -1) {
            return memo[i][holding];
        }
        
        if(holding) {
            //you are holding the stock either sell
            // or keep it
            return memo[i][holding]= max(prices[i] + dp(i+2,0,prices),dp(i+1,1,prices));
        }else {
            //you don't have stock so buy or don't buy
            return memo[i][holding]=max(-prices[i]+dp(i+1,1,prices),dp(i+1,0,prices));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        return dp(0,0,prices);
    }
};
