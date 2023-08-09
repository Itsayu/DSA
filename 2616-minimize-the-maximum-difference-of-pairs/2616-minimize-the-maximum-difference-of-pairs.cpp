class Solution {
public:
    int n;
    bool numsPairs(vector<int>& nums, int diff, int p){
        int c=0;
        for(int i=0; i<n-1; i++)
            if (nums[i+1]-nums[i]<=diff) {
                c++;
                if (c>=p)
                    return 1;
                i++;
            }
        return 0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if (p==0)
            return 0;
        n=nums.size();
        sort(nums.begin(), nums.end());

        int l=0, r=nums[n-1]-nums[0], m, ans;
        while(l<=r){
            m=l+(r-l)/2;
            if (numsPairs(nums, m, p)){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        
        return ans;   
    }
};