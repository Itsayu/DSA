class Solution {
public:
    int ans=0;
    
    void solve(vector<int>&nums,int k,vector<int>&v,int i)
    {
        if(i>=nums.size())
        {
            ans++;
            return;
        }
        bool flag=true;
        for(int j=0;j<v.size();j++)
        {
            if(abs(v[j]-nums[i])==k)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            v.push_back(nums[i]);
            solve(nums,k,v,i+1);
            v.pop_back();
        }
        solve(nums,k,v,i+1);
    }
    
    
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back(nums[i]);
            solve(nums,k,v,i+1);
            v.pop_back();
        }
        return ans;
    }
};