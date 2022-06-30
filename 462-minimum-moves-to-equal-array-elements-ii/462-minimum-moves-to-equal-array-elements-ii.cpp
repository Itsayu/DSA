class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        int x=n/2;
        int ayu=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            ayu+=abs(nums[i]-nums[x]);
        }
        return ayu;
    }
};