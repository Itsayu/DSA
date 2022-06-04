class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ayu=0;
        int n=nums.size();
        if(n==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                nums[ayu++]=nums[i];
            }
        }
        return ayu;
    }
};