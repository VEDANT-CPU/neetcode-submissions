class Solution {
public:
    bool isPalindrome(string s) {
        int l;
        int r;
        erase(s,' ');
        
    for(int i=0; i<s.size(); i++) {
            int ascii = s[i];
            if(ascii >= 97 && ascii <= 122) ;
            else if(ascii >= 65 && ascii <= 90) ;
            else if(ascii >= 48 && ascii <= 57) ;
            else {s.erase(i,1); i--;}
    }
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    int n = s.size();
        l = 0;
        r = n-1;
        while(l <= r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
