class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
		unordered_map<int,int> mp;
		int n=nums.size();
		if(n==1)
			return false;
		if(k==1)
			return true;        
		int mod=nums[0]%k;
		mp[mod]=0;
		for(int i=1;i<n;i++)
		{
			mod=(mod+nums[i])%k;
			if(mod==0|| (mp.find(mod)!=mp.end() && mp[mod]!=i-1  ))
				return true;
			if(mp.find(mod)==mp.end())
				mp[mod]=i;

		}
		return false;   
    }
};