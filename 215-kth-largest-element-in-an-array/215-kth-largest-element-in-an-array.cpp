class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = nums[0];
        sort(nums.begin(), nums.end(), greater<int>());
        res = nums[k-1];
        return res;
    }
};