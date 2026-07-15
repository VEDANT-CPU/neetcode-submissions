class Solution {
public:
    vector<vector<int>> res;
    vector<int>vec;

    void dfs(int index, vector<int>& nums) {
        if(index >= nums.size()) {
            res.push_back(vec);
            return;
        }

        vec.push_back(nums[index]);
        dfs(index+1, nums);
// Assume nums array is sorted.
        while(index<nums.size()-1 && nums[index]==nums[index+1]) {
            index++;
        }

        vec.pop_back();
        dfs(index+1, nums);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0,nums);
        return res;
    }
};
