class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len=0;
        int i=0;
        int j=0;
        int n = s.size();
        unordered_set<char> ms;
        while(j < n) {
            if(!ms.contains(s[j])) {
                ms.insert(s[j]);
            }else {
                while(ms.contains(s[j])) {
                    ms.erase(s[i]);
                    i++;
                }
                ms.insert(s[j]);
            }
            max_len = max(max_len, (int) ms.size());
            j++;
        }
        return max_len;
    }
};
