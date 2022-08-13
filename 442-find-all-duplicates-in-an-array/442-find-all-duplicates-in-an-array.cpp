class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ayu;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1])
                ayu.push_back(nums[i]);
        }
        return ayu;
    }
};