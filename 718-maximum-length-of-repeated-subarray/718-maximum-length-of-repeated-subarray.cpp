class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int nr=nums1.size();
        int akt=nums2.size();
        int dp[nr+1][akt+1];
    
        for(int i=0; i<akt+1; i++)
            dp[0][i]=0;
        for(int i=0; i<nr+1; i++)
            dp[i][0]=0;
    
        int maxi=INT_MIN;
        for(int i=1; i<nr+1; i++){
            for(int j=1; j<akt+1; j++){
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j]=1 + dp[i-1][j-1];
                else
                    dp[i][j]=0;
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi;
    }
};