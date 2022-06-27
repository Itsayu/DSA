class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int m=0;
        int n=nums.size()-1;
        int ayu=0;
        while (m<n){
            if(nums[m]+nums[n]==k){
                m++;
                n--;
                ayu++;
            }
            else if(nums[m]+nums[n]<k)
                m++;
            else
                n--;
        }
        return ayu;
    }
};