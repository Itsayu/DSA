class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ayu=nums[0];
        sort(nums.begin(), nums.end(), greater<int>());
        ayu=nums[k-1];
        return ayu;
    }
};