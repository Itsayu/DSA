class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, h=nums.size()-1;
        while(l<h){
            int m = l + (h-l)/2;
            if(nums[m]==nums[m-1]){
                if((m-1-l)%2) h=m-2;
                else l=m+1;
            }
            else if(nums[m]==nums[m+1]){
                if((h-m-1)%2) l=m+2;
                else h=m-1;
            }
            else return nums[m];
        }
        return nums[l];  
    }
};