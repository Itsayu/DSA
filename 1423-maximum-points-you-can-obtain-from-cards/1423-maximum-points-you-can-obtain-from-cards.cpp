class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int>prefixsum(n,0);
        int x=0;
        for(int i=0;i<n;i++){
            x+=cardPoints[i];
            prefixsum[i]=x;
        }
        if(k==n)
            return x;
        int ans=x-prefixsum[n-k-1]; 
        int summ;
        for(int i=1;i<k+1;i++){
            int j=i+(n-k)-1;
            summ=prefixsum[j]-prefixsum[i-1];
            ans=max(ans,x-summ);
        }
        return ans;
    }
};