class Solution {
public:
    vector<vector<int>> dp;
    int n,m;
    
    int f(vector<int>& a, vector<int>& b,int i,int j,int p)
    {
        if(i==n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=1e8;
        if(a[i]>p)
            ans=f(a,b,i+1,upper_bound(b.begin(),b.end(),a[i])-b.begin(),a[i]);
        if(j!=m)
            ans=min(ans,1+f(a,b,i+1,upper_bound(b.begin(),b.end(),b[j])-b.begin(),b[j]));
        return dp[i][j]=ans;
    }
    
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        n=a.size();
        m=b.size();
        dp.resize(n,vector<int>(m+1,-1));
        sort(b.begin(),b.end());
        int ans=f(a,b,0,0,-1);
        return ans>=1e8?-1:ans;
    }
};