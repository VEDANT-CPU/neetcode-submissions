class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(),nums.end());
        int curMax=1;
        int curMin=1;
        for(int i=0; i<nums.size(); i++) {
            
                if(nums[i]==0) {
                    curMax = 1;
                    curMin = 1;
                    continue;
                }
                int temp = curMax;
                curMax = max(nums[i]*curMax,nums[i]*curMin);
                curMin = min(nums[i]*temp,min(nums[i]*curMin,nums[i]));

            res = max(res,curMax);
        }
        return res;
    }
};
