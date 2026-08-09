class Solution {
public:

    int climbStairs(int n) {
        vector<int>suff(2);
        suff[1] = 1;
        for(int i=n-1; i>=0; i--) {
            if(i==n-1) suff[0] = suff[1];
            else {
                int temp = suff[0]+suff[1];
                suff[1] = suff[0];
                suff[0] = temp;
            }
        }
        return suff[0];
    }
};
