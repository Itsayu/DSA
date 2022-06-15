class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int ayu=nums.size();
        for(int i=0; i<ayu;i++){
           if(i==0)
                nums[i]=nums[i];
           else
                nums[i]=nums[i]+nums[i-1];
            
        }
        return nums;
    }
};