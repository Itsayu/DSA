class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map <int, int> ayu;
    //     for(int i=0; i<nums.size();i++){
    //         if(ayu.count (target - nums[i]))
    //             return{i,ayu[target - nums[i]]};
    //         ayu[nums[i]]=i;
    //     }
    //     return {-1,-1};
    
    for(int i = 0;i<nums.size() - 1;i++){
            for(int j =i+1;j<nums.size();j++){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {0,0};
    }
};