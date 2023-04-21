class Solution {
public:
    int dp[101][101][101];
    int mod=1e9+7;
    int helper(int i, int n, int minProfit, vector<int>&group, vector<int>&profit)
    {
        if(i==group.size()){
            if(minProfit<=0&&n>=0) return 1;
            return 0;
        }
        if(minProfit<0) minProfit=0;
        if(dp[i][n][minProfit]!=-1) return dp[i][n][minProfit];
        int pick=0;
        if(group[i]<=n){
            pick=helper(i+1,n-group[i],minProfit-profit[i],group,profit);
        }
        int notpick=helper(i+1,n,minProfit,group,profit);
        return dp[i][n][minProfit]=((pick)%mod+(notpick)%mod)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return helper(0,n,minProfit,group,profit);
    }
};