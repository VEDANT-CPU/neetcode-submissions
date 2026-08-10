class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();//top point is n
        vector<int>dp(N+1);
        for(int j=N-1; j>=0; j--) {
            if(j==N-1 || j==N-2) {
                dp[j] = cost[j];
            }else {
                dp[j] = min(cost[j]+dp[j+1],cost[j]+dp[j+2]);
            }
        }
        return min(dp[0],dp[1]);
    }
};
