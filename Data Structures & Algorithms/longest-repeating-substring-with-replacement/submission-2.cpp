class Solution {
public:
    int max_frequency(unordered_map<char,int>& sub_f) {
        auto freq = max_element(
                sub_f.begin(),
                sub_f.end(),
                [](const auto& a,const auto& b){
                    return a.second < b.second;
                }
        );
        return freq->second;
    }
    
    int characterReplacement(string s, int k) {
        int i=0;
        int j=1;
        unordered_map<char,int>sub_f;
        sub_f[s[i]]++;
        int max_len=1;
        while(j < s.size()) {
            sub_f[s[j]]++;
            int freq = max_frequency(sub_f);
            int sub_len = j-i+1;
            int replacements = sub_len - freq;
            while(replacements > k) {
                sub_f[s[i]]--;
                if(sub_f[s[i]] == 0) sub_f.erase(s[i]);
                i++;
                freq = max_frequency(sub_f);
                sub_len = j-i+1;
                replacements = sub_len - freq;

            }
            max_len = max(max_len,sub_len);
            j++;
        }
        return max_len;
    }
};
