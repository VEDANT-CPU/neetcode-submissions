class Solution {
public:
    vector<vector<int>> res;
    vector<int>subarr;
    
    /*int Powerof2(int nums) {
        if(nums==0) return 1;
        return 2 * Powerof2(--nums);
    }*/

    void dfs(int index, int size, vector<int>& nums) {
        if(index >= size) {
            vector<int>subarr_copy(subarr.begin(),subarr.end());
            res.push_back(subarr_copy);
            return;
        }
        //decision of including the element
        subarr.push_back(nums[index]);
        dfs(index+1,size,nums);

        //decision to not include the element
        subarr.pop_back();//remove last as its recursion
        //we are coming from the end.
        dfs(index+1,size,nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        dfs(0,size,nums);
        return res;
    }
};
