class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long count = 0;
        for(int num : nums)
        {
            if(num != 0) count = 0;
            else
            {
                count++;
                ans += count;
            }
        }
        
        return ans;
    }
};