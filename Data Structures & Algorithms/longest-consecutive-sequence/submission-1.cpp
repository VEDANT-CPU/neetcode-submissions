class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        set<int>working;
        for(int x : nums) {
            working.insert(x);
        }
        int len=1;
        int max_len=1;
        auto it = working.begin();
        auto next_it = next(it,1);
        while(next_it != working.end()) {
            if((*next_it)-(*it) == 1){
                len++;
            }else {
                if(len > max_len) max_len = len;
                len = 1;
            }
            ++it;
            next_it = next(it, 1);
        }
        if(len > max_len) max_len = len;
        return max_len;
    }
};
