class Solution {
public:
    vector<int>memo;
    int dfs(int i,int cur,vector<int>& nums) {
        int max_cnt=0;
        for(int j=i; j<nums.size(); j++) {
            int cnt = 0;
            if(nums[j] > cur) {
                if(memo[j] != -1) {
                    cnt += memo[j];
                }else {
                    memo[j]= dfs(j+1,nums[j],nums)+1;
                    cnt = memo[j];
                }
            }
            max_cnt = max(cnt, max_cnt);
        }
        return max_cnt;
    }


    int lengthOfLIS(vector<int>& nums) {
        int cur = INT_MIN;
        memo.resize((int)nums.size(),-1);
        return dfs(0,cur,nums);
    }
};
