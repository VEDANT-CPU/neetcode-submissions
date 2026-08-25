class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>cache(amount+1,INT_MAX);
        cache[0] = 0;

        for(int i=1; i<=amount; i++) {
            for(int j=0; j<coins.size();j++) {
                int temp = i - coins[j];
                if(temp>=0) {
                    if(cache[temp]<cache[i]) {
                        cache[i] = cache[temp]+1;
                    }
                }
            }
        }

        if(cache[amount]==INT_MAX) return -1;
        return cache[amount];
    }
};
