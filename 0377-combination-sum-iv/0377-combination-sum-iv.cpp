class Solution {
public:
    int solve(vector<int>& nums,vector<int>& dp, int target) {
        if(target < 0) {
            return 0;
        }
        if(target == 0) {
            return 1;
        }
        if(dp[target] != -1)
            return dp[target];
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans += solve(nums, dp, target - nums[i]);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> dp(target + 1, -1);
        return solve(nums, dp, target);
        
    }
};