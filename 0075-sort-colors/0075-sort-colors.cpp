class Solution {
public:
    void sortColors(vector<int>& nums) {
        int k1=-1,k2=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(k1!=-1 && k1<n) swap(nums[k1++],nums[i]);
                if(k2<n) swap(nums[k2++],nums[i]);
            }
            else if(nums[i]==1){
                if(k1==-1) k1=k2;
                if(k2<n) swap(nums[k2++],nums[i]);
            }
        }
    }
};