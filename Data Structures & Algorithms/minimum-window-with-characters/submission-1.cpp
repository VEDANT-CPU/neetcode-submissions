class Solution {
public:
    bool MapContains(unordered_map<char,int>& mp1, unordered_map<char,int>& mp2) {
        int cnt=0;
        for(const auto& pair : mp1) {
            if(mp2.find(pair.first) != mp2.end()) {
                //cnt++;
                auto it = mp2.find(pair.first);
                if(it->second >= pair.second) cnt++;
                else break;
            }else break;
        }
        if(cnt == mp1.size()) return true;
        return false;
    }

    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int i=0; i<t.size(); i++) {
            mp1[t[i]]++;
        }
        if(s.size() < t.size()) {
            return res;
        }
        int i=0;
        int j=t.size()-1;
        for(int k=i; k<=j; k++) {
            mp2[s[k]]++;
        }
        int min_len=s.size();
        //bool f1 = false;
        while(j < s.size()) {
            while(MapContains(mp1,mp2)) {
                //f1 = true;
                if(min_len >= j-i+1) {
                    min_len = j-i+1;
                    res = s.substr(i,min_len);
                }
                //min_len = min(min_len, j-i+1);
                //res = s.substr(i,min_len);
                mp2[s[i]]--;
                if(mp2[s[i]] == 0) mp2.erase(s[i]);
                i++;
            }
            j++;
            if(j < s.size()) mp2[s[j]]++;
        }
        return res;
    }
};
