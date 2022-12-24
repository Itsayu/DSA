class Solution {
public:
    int numTilings(int n) {
       int modval = 1e9 + 7;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) dp[i] = (dp[i] + ((i - j <= 2) ? dp[j] : 2 * dp[j] % modval)) % modval;
        }
        return dp[n]; 
    }
};