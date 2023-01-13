class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> nr;
        
        for(int i=0;i<nums.size();i++) {
            int val = abs(nums[i]);
            
            int pos = val-1;
            
            if(nums[pos] < 0) {
                nr.push_back(val);
            } else {
                nums[pos] = -nums[pos];
            }
        }
        return nr;
    }
};