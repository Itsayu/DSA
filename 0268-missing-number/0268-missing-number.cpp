class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        int sum1 = 0;
        for(int i=0; i<=len; i++){
            sum += i;
        }
        for(int j=0; j<len; j++){
            sum1 += nums[j];
        }
        return (sum - sum1);
    }
};