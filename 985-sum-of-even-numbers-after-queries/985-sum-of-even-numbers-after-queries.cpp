class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sume = 0;
        for(auto &i:nums){
            if(i%2==0) sume += i;
        }
        int orig, changed;
        int val,index;
        for(auto i: queries){
            int val = i[0];
            int index = i[1];
            if(nums[index]%2==0) orig = nums[index];
            else orig = 0;
            nums[index] += val;
            if(nums[index]%2==0) changed = nums[index];
            else changed = 0;
            sume += (changed - orig);
            ans.push_back(sume);
        }
        return ans;
    }
};