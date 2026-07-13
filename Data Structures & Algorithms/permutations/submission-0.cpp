class Solution {
public:
    vector<vector<int>> res;
    vector<int> vec;
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return {{}};
        vector<int>n(nums.begin()+1,nums.end());
        vector<vector<int>> perm = permute(n);
        vector<vector<int>> res;
        for(vector<int>& p : perm) {
            for(int i=0; i<=p.size(); i++) {
                vector<int> p_copy(p.begin(),p.end());
                p_copy.insert(p_copy.begin()+i,nums[0]);
                res.push_back(p_copy);
            }
        }
        return res;
    }
};
