class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ayu=INT_MIN;
        int m=0;
        int n=nums.size()-1;
        while(m<n){
            ayu=max(nums[m]+ nums[n],ayu);
            m++;
            n--;
        }
        return ayu;
    }
};