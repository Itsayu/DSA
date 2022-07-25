class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(binary_search(nums.begin(),nums.end(),target)){
            int firstOccurence,lastOccurence;
            firstOccurence=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            lastOccurence=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
            return {firstOccurence,lastOccurence};
        }
        return {-1,-1};
    }
};