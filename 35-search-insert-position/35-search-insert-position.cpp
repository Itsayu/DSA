class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ayu=nums.size();
        int low=0;
        int high=ayu-1;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
};