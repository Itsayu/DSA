class Solution {
public:
    vector<int> dp;
    int play(int i, vector<int>& stoneValue, int n){
        if (dp[i]!=INT_MIN) return dp[i];
        int result=stoneValue[i]-play(i+1, stoneValue, n);
        if (i+2<=n)
            result=max(result,
            stoneValue[i]+stoneValue[i+1]-play(i+2, stoneValue, n));
        if (i+3<=n)
            result=max(result,
            stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-play(i+3, stoneValue, n));
        return dp[i]=result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n+1, INT_MIN);
        dp[n]=0;
        int win=play(0, stoneValue,  n);
        if (win>0) return "Alice";
        if (win<0) return "Bob";
        return "Tie";
    }
};