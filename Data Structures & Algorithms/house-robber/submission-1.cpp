class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>robbed(nums.size());
        for(int j=nums.size()-1; j>=0; j--) {
            if(j==nums.size()-1 || j==nums.size()-2) {
                robbed[j] = nums[j];
            }else if(j==nums.size()-3) {
                robbed[j] = nums[j]+robbed[j+2];
            }
            else {
                robbed[j]=nums[j]+max(robbed[j+3],robbed[j+2]);
            }
        }
        if(nums.size() > 1) return max(robbed[0],robbed[1]);
        return robbed[0];
    }
};
