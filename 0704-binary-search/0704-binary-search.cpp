class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();   
        int low=0;
        int max=n-1;
        
        while (low<=max){
            int mid=(low+max)/2;
            if (nums[mid]==target){
                return mid;
            }
            else if (nums[mid]>target){
                max=mid-1;
            }
            else low=mid+1;
        }
        return -1;
    }
};