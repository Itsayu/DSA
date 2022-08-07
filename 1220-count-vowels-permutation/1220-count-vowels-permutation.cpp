class Solution {
public:
    int countVowelPermutation(int n) {
        long mod = 1e9 + 7;
		vector<vector<long long>> dp(n, vector<long long>(5, 0));
        
        for (int i=0; i<5; i++) {
            dp[0][i] = 1;
        }
        
        for (int i=1; i<n; i++) {
            // a = e + i + u
            dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4]) % mod;
            // e = a + i
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % mod;
            // i = e + o
            dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % mod;
            // o = i
            dp[i][3] = (dp[i-1][2]) % mod;
            // u = i + o
            dp[i][4] = (dp[i-1][2] + dp[i-1][3]) % mod;
        }
        
        return (dp[n-1][0] + dp[n-1][1] + dp[n-1][2] + dp[n-1][3] + dp[n-1][4]) % mod;
    }
};