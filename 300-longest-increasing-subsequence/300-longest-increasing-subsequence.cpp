class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
		int n = nums.size(), len=1;
		temp.push_back(nums[0]);
		for(int i=0;i<n;i++)
			if(nums[i]>temp.back()) {
				len++;
				temp.push_back(nums[i]);
			}
			else{
				int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
				temp[ind] = nums[i];
			}
		return len;
    }
};