class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int maxday=days[n-1];
        vector<int> dp(maxday+1,0);
        for(int i=0;i<n;++i){
            dp[days[i]]=-1;
        }
        for(int i=1;i<=maxday;++i){
            if(dp[i]==0){
                dp[i]=dp[i-1];
            }
            else{
                if(i-30>=0){
                    dp[i]=min(dp[i-1]+costs[0],min(dp[i-7]+costs[1],dp[i-30]+costs[2]));
                }else if(i-7>=0){
                    dp[i]=min(dp[i-1]+costs[0],min(dp[i-7]+costs[1],costs[2]));
                }else{
                    dp[i]=min(dp[i-1]+costs[0],min(costs[1],costs[2]));
                }
            }
        }
        return dp[maxday];
    }
};