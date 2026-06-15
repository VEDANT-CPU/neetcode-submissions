class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int i = 0;
        int j = i+1;
        int n = prices.size();
        while(j < n && i < n) {
            if(prices[j]>prices[i]) {
                int profit = prices[j]-prices[i];
                max_profit = max(max_profit,profit);
            }else {
                i = j;
            }
            j++;
        }
        return max_profit;
    }
};
