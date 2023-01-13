class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> nr;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                nr.push_back(nums[i]);
            }
        }
        return nr;
    }
};