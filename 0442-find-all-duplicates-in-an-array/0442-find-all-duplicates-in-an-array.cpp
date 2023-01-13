class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ayu;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                ayu.push_back(nums[i]);
            }
        }
        return ayu;
    }
};