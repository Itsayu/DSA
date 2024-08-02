class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int N = nums.size();
        int prefix[2 * N + 1];
        prefix[0] = 0;
        
        for (int i = 1; i <= 2 * N; i++) {
            prefix[i] = prefix[i - 1] + nums[(i - 1) % N];
        }
        
        int ones = prefix[N];
        int good = -1;
        for (int i = 0; i < N; i++) {
            good = max(good, prefix[i + ones] - prefix[i]);
        }
        
        return ones - good;
    }
};