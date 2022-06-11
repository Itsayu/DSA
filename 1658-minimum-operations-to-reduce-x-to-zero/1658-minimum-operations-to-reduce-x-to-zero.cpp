class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l=0, r=nums.size()-1, ans=INT_MAX;
        while(l<nums.size() and x-nums[l]>0)
            x-=nums[l++];
        
        if(x>0 and l==nums.size())
            return -1;
        x-=nums[l];
        if(x==0)
            ans=l+1;
        while(l>=0){
            if(l>=0)
                x+=nums[l--];
            while(r>l and x>0)
                x-=nums[r--];
            if(x==0)
                ans=min(ans,1+l+(int)nums.size() -r-1);  
        }        
        return ans==INT_MAX?-1:ans;
    }
};