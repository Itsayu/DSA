class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
      vector<int> diff(nums.size());
      long long sum=0;
      for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        diff[i]=(nums[i]^k)-nums[i];
      } 
      sort(diff.rbegin(),diff.rend());
      if(diff.size()%2==1){
        diff.pop_back();
      } 
      for(int i=0;i<diff.size()-1;i+=2){
        if((diff[i]+diff[i+1])>0) sum+=(diff[i]+diff[i+1]);
      }
      return sum;
    }
};