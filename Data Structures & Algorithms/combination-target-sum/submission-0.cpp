class Solution {
public:
    vector<vector<int>>res;
    vector<int> subList;
    

    void dfs(int index,int target,vector<int>& nums) {
        if(index >= nums.size() || target<=0) {
            if(target==0) res.push_back(subList);
            return;
        }
        //decision to choose the current element;
        subList.push_back(nums[index]);
        dfs(index,target-nums[index],nums);

        //decision to not include
        subList.pop_back();
        dfs(index+1,target,nums);
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0,target,nums);
        return res;
    }
};
