class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int curMax = 1;//largest product of subarray ending at that index
        int curMin = 1;

        for(int i=0; i<nums.size(); i++) {
            int temp = curMax * nums[i];
            curMax = max(nums[i],max(curMax*nums[i],curMin*nums[i]));
            curMin = min(nums[i],min(temp,curMin*nums[i]));
            res = max(res,curMax);
        }
        return res;
    }
};
