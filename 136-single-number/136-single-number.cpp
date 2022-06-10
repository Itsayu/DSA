class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int nr=nums.size();
        int ayu=0;
        for(int i=0; i<nr; i++){
            ayu^=nums[i];
        }
        return ayu;
    }
};


// PYTHON

// ayu=0
//         for i in nums:
//             ayu^=i
//         return ayu