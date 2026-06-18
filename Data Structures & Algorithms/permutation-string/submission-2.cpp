class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        bool res = false;
        if(m < n) {
            return false;
        }
        unordered_map<char,int>mp;
        unordered_map<char,int>mp2;
        for(int i=0; i<n; i++) {
            mp[s1[i]]++;
        }
        int i=0;
        int j = n-1;
        for(int k=i; k<=j; k++) {
            mp2[s2[k]]++;
        }
        while(j < m) {
            if(mp2 == mp) return true;
            
            mp2[s2[i]]--;
            if(mp2[s2[i]] == 0) mp2.erase(s2[i]);
            i++;
            j++;
            mp2[s2[j]]++;
        }
        //if(res) return true;
        return false;
    }
};
