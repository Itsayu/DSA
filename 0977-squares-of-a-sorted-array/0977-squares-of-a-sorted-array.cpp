class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int nr = nums.size();
        for(int i=0; i<nr; i++){
            nums[i] *= nums[i];
        }
        int leftPtr = 0;
        int rightPtr = nr-1;
        
        vector<int> ans(nr,0);
        for(int i=nr-1; i>=0; i--){
            if(nums[leftPtr] >= nums[rightPtr]){
                ans[i] = nums[leftPtr];
                leftPtr++;
            }
            else{
                ans[i] =nums[rightPtr];
                rightPtr--;
            }
        }
        return ans;
    }
};