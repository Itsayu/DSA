class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        int a[n+1][m+1];
        memset(a,0,sizeof a);
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                    a[i][j]=1+a[i-1][j-1];
                else
                    a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
        return n-a[n][m]+m-a[n][m];
    }
};