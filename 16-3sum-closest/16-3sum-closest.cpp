class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans, diff = 100000;
        for(int i=0; i<n-2; i++){
            int j = i+1, k = n-1, currSum;
            while(j<k){
                currSum = nums[i] + nums[j] + nums[k];
                if(currSum<target)j++;
                else if(currSum>target)k--;
                else j++,k--;
                if(abs(currSum-target)<diff){
                    diff = abs(currSum - target);
                    ans = currSum;
                }
            }
        }
        return ans;
    }
};