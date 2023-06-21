class Solution {
public:
    long long computeCost(vector<int>& nums, vector<int>& cost, int tar) {
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++)
            res += 1ll*abs(nums[i] - tar)*cost[i];
        return res;
    }
 

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low = 0 , high = 1e6;
        long long ans = 0;
        
        while(low < high) {
            int mid = (low + high) >> 1;
            
            long long x = computeCost(nums,cost,mid);
            long long y = computeCost(nums,cost,mid+1);
            
            ans = min(x,y);
            if(x < y) high = mid;
            else low = mid + 1;
        }
        return ans;
    }
};