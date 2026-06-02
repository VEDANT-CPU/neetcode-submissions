class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r = numbers.size()-1;
        while(l < r) {
            int numsum = numbers[l] + numbers[r];
            if(numsum < target) l++;
            else if(numsum > target) r--;
            else break;
        }
        l++;
        r++;
        return {l,r};
    }
};
