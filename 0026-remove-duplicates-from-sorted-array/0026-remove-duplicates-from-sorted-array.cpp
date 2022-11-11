class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 0){
            return 0;
        }
        int count = 0;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[count]){
                count++;
                nums[count] = nums[i];
            }
        }
        return count + 1;
    }
};