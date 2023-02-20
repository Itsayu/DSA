class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st=0; int end=nums.size()-1;
        int ans=0;
        while(st<=end){
            int mid=(st+end)/2;
            if(nums[mid]<target){
                st=ans=mid+1;
                
            }
            else if(nums[mid]>target){
                end=mid-1;
            }else{
                return mid;
            }
        }
        return ans;
    }
};