class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>output(n);
        int product=1;
        int zero_cnt = 0;
        for(int x : nums) {
            if(x != 0) product *= x;
            else zero_cnt += 1;
        }
        for(int i=0;i<n; i++) {
            if(zero_cnt > 1) {
                output[i] = 0;
            }else if(zero_cnt == 1){
                if(nums[i] == 0) output[i] = product;
                else output[i] = 0;
            }else {
                output[i] = product / nums[i];
            }
        }
        return output;
    }
};
