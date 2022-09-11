class Solution {
private:
    void solve(vector<int> nums, vector<vector<int>>& nr, int index){
        if(index >= nums.size()){
            nr.push_back(nums);
            return;
        }
        for(int j = index; j < nums.size(); j++){
            swap(nums[index], nums[j]);
            solve(nums, nr, index+1);
            swap(nums[index], nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>akt;
        int index = 0;
        solve(nums, akt, index);
        return akt;
    }
};