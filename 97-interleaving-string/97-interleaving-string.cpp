class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(),m=s2.length(),t=s3.length();
        if(n+m!=t) return false;
        
        bool dp[n+1][m+1];
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;
        
        for(int i=1;i<=n;i++) dp[i][0]= dp[i-1][0] && s1[i-1]==s3[i-1];
            for(int i=1;i<=m;i++) dp[0][i]= dp[0][i-1] && s2[i-1]==s3[i-1];
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s3[i+j-1] &&dp[i-1][j])
                    dp[i][j]=true;
                 else if(s2[j-1]==s3[i+j-1] && dp[i][j-1])
                    dp[i][j]=true;
            }
        }
        
        return dp[n][m];
    }
};