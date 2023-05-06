class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9+7;
        int n = nums.size();
        
        vector<int>pow = {1};
        for(int i=0;i<n;i++)
        pow.push_back((pow.back()*2)%mod);

        int l=0,r=n-1,ans =0;
        sort(nums.begin(),nums.end());
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                ans =(ans+pow[r-l])%mod;
                l++;
            }
            else 
            r--;
        }
        return ans;
    }
};