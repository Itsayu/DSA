class Solution {
public:
    int dp[1001][1001];
    int solve(string &s1, string &s2, int m, int n)
    {
        if(m==s1.length() || n==s2.length())
            return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        if(s1[m]==s2[n])
            return dp[m][n] = 1 + solve(s1, s2, m+1, n+1);
        else
            return dp[m][n] = max(solve(s1, s2, m+1, n), solve(s1, s2, m, n+1));
    }
    int longestCommonSubsequence(string s1, string s2) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, 0);
    }
};