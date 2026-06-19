class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) {
            return "";
        }
        unordered_map<char,int>window;
        unordered_map<char,int>str_t;
        for(int i=0; i<t.size(); i++) {
            str_t[t[i]]++;
        }
        for(int i=0; i<t.size(); i++) {
            window[t[i]]=0;
        }
        int i=0;
        int j=0;
        int condition=0;
        string res="";
        int min_len = s.size();
        while(j < s.size()) {
            if(t.contains(s[j])) {
                window[s[j]]++;
                if(window[s[j]] == str_t[s[j]]) {
                    condition++;
                }
            }
            while(condition == str_t.size()) {
                if(min_len >= j-i+1) {
                    min_len = j-i+1;
                    res = s.substr(i, min_len);
                }
                if(t.contains(s[i])) {
                    window[s[i]]--;
                    if(window[s[i]] < str_t[s[i]]) {
                        condition--;
                    }
                }
                i++;
            }
            j++;
        }
        return res;
    }
};
