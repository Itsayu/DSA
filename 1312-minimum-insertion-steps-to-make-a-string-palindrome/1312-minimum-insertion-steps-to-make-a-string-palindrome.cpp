class Solution {
public:
    int minInsertions(string str) {
        string a=str;
        int n=str.size();
        reverse(str.begin(),str.end());
        int nr[n+1][n+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                    nr[i][j]=0;
                else if(str[i-1]==a[j-1])
                    nr[i][j]=1+nr[i-1][j-1];
                else 
                    nr[i][j]=max(nr[i-1][j],nr[i][j-1]);
            }

        }
        return n-nr[n][n]; 
    }
};