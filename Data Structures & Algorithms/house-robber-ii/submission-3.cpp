class Solution {
public:
    int dp1(vector<int>& nums,int index) {
        if(index >= nums.size()-1) return 0;

        return max(dp1(nums,index+1),nums[index]+dp1(nums,index+2));
    }

    int dp2(vector<int>& nums,int index) {
        if(index >= nums.size()) return 0;

        return max(dp2(nums,index+1),nums[index]+dp2(nums,index+2));
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>dp1(nums.size()-1);
        vector<int>dp2(nums.size()-1);
        for(int i=0; i<dp1.size(); i++) {
            if(i==0) {
                dp1[i]=nums[0];
            }else if(i==1) {
                dp1[i]=max(nums[0],nums[1]);
            }else {
                dp1[i] = max(nums[i]+dp1[i-2],dp1[i-1]);
            }
        }
        for(int i=1; i<nums.size(); i++) {
            if(i==1) {
                dp2[i-1]=nums[1];
            }else if(i==2) {
                dp2[i-1]=max(nums[1],nums[2]);
            }else {
                dp2[i-1] = max(nums[i]+dp2[i-3],dp2[i-2]);
            }
        }
        return max(dp1[dp1.size()-1],dp2[dp2.size()-1]);
    }
};
