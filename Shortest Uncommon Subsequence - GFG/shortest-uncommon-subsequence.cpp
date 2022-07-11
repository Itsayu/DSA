// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int shortestUnSub(string S, string T) {
        // code here
        int n=S.length(),m=T.length(),max=1e3,dp[n+1][m+1];
        for(int i=1;i<=n;i++) dp[i][0]=1;
        for(int j=0;j<=m;j++) dp[0][j]=max;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                int k=j;
                for(k;k>=0;k--)
                    if(S[i]==T[k])
                        break;
                if(k<0)
                    dp[i+1][j+1]=1;
                else
                    dp[i+1][j+1]=min(dp[i][j+1], 1+dp[i][k]);
            }
        return dp[n][m]>=max ? -1 : dp[n][m];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends