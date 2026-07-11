class Solution {
public:
    vector<vector<int>> res;
    vector<int> combo;
    //Time complexity of dfs is 2^n.
    void dfs(int index, int target, vector<int>& candidates) {
        if(index >= candidates.size() || target<=0) {
            if(target==0) {
                res.push_back(combo);
            }
            return;
        }
        //decision tree to include the element.
        combo.push_back(candidates[index]);
        dfs(index+1,target-candidates[index],candidates);
        //candidates must be sorted.
        while(index<candidates.size()-1 && candidates[index] == candidates[index+1]) index++;
        //After loop candidates[index+1] won't be a duplicate
        //decision tree to not include element
        combo.pop_back();
        dfs(index+1,target,candidates);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0,target,candidates);

        return res;
    }
};
