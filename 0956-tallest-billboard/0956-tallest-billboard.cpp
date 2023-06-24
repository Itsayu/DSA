class Solution {
public:
    int n;
  int f(int i, int s, vector<int> &rods, vector<vector<int>> &dp){
    if(i >= n){
      // check if we can form s sum using no elements and returns its value;
      if(s == 5000)return 0;
      else return INT_MIN;
    }

    if(dp[i][s] != INT_MIN)return dp[i][s];
    int ans = f(i+1, s, rods, dp); //ignore case
    ans = max(ans, f(i+1, s-rods[i], rods, dp));
    ans = max(ans, rods[i] + f(i+1, s+rods[i], rods, dp));
    return dp[i][s] = ans;
  }



    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        vector<vector<int>> dp(n, vector<int>(10001, INT_MIN));
        return f(0, 5000, rods,dp);
    }
};