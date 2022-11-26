class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> arr(n);
        for(int i = 0; i < n; i++){
            int start = startTime[i];
            int end = endTime[i];
            int profitt = profit[i];
            arr[i] = {end, start, profitt};
        }
        sort(arr.begin(), arr.end());
        vector<int> dp(n, 0);
        dp[0] = arr[0][2];
        
        for(int i = 1; i < n; i++){
            int include = arr[i][2];
            int low = 0;
            int high = n - 1;
            int last_idx = -1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(arr[mid][0] <= arr[i][1]){
                    last_idx = mid;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            if(last_idx != -1){
                include += dp[last_idx];
            }
            int exclude = dp[i - 1];
            dp[i] = max(include, exclude);
        }
        
        return dp[n - 1];   
    }
};