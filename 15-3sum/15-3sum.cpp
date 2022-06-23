class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        int left, right, sum=0;
        for (int i=0; i<nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            left = i+1; right=nums.size()-1;
            while (left < right) {
                sum = nums[left] + nums[right] + nums[i];
                
                if (sum > 0) right--;
                
                else if (sum < 0) left++;
                
                else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++; 
                    while (nums[left] == nums[left-1] && left < right) left++;
                }   
            }
        }
        return result;
    }
};