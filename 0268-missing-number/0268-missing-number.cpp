class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int flag = 0;
            for (int j = 0; j < len; j++) {
                if (nums[j] == i) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                return i;
            }
        }
        return len;
    }
};