class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> ayu;
        for(int i=0; i<nums.size();i++){
            if(ayu.count (target - nums[i]))
                return{i,ayu[target - nums[i]]};
            ayu[nums[i]]=i;
        }
        return {-1,-1};
    }
};