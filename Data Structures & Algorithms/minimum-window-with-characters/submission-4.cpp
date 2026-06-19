class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        int min_len = INT_MAX;
        int i=0;
        int sInd=i;
        int j=0;
        unordered_map<char,int> mp;
        for(int i=0; i<t.size(); i++) {
            mp[t[i]]++;
        }
        int cnt = 0;
        while(j < s.size()) {
            if(mp[s[j]] > 0) {
                cnt++;
            }
            mp[s[j]] -= 1;
            while(cnt == t.size()) {
                if(min_len >= j-i+1) {
                    min_len = j-i+1;
                    sInd = i;
                }
                mp[s[i]] += 1;
                if(mp[s[i]] > 0) {
                    cnt--;
                }
                i++;
            }
            j++;
        }
        if(min_len > s.size()) min_len = 0;
        string res = s.substr(sInd, min_len);
        return res;
    }
};
