class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int ayu=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1])
                continue;
            else{
                ayu++;
            if(i>0)
                if(nums[i+1]<nums[i-1])
                    nums[i+1]=nums[i];
                }
            }
            if(ayu<=1)
                return true;
        return false;
    }
};