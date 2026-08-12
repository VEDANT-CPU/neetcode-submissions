class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int ans_len=0;
        for(int i=0; i<s.size(); i++) {
            //for odd length palindromes
            int l=i;
            int r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]) {
                if(r-l+1 > ans_len) {
                    ans = s.substr(l,r-l+1);
                    ans_len = r-l+1;
                }
                l--;
                r++;
            }
            //for even length string
            l=i;
            r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]) {
                if(r-l+1 > ans_len) {
                    ans = s.substr(l,r-l+1);
                    ans_len = r-l+1;
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};
