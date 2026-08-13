class Solution {
public:
    int numDecodings(string s) {
    int n = s.size();
    if (n == 0 || s[0] == '0') return 0; // Empty string or leading zero cannot be decoded

    // dp[i] represents the number of ways to decode the prefix s[0...i-1]
    vector<int> dp(n + 1, 0);

    // Base cases
    dp[0] = 1; // Base case for empty prefix (used when taking a 2-digit number at the start)
    dp[1] = 1; // First character is already checked to be non-zero

    for (int i = 2; i <= n; i++) {
        // Option 1: Take 1 digit (s[i-1])
        int oneDigit = s[i - 1] - '0';
        if (oneDigit >= 1 && oneDigit <= 9) {
            dp[i] += dp[i - 1];
        }

        // Option 2: Take 2 digits (s[i-2..i-1])
        int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (twoDigits >= 10 && twoDigits <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}
};
