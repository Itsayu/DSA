class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long> pq;
        for (int& num : nums) {
            pq.push(num);
        }

        long long ans = 0;
        while (k--) {
            double maxNum = pq.top();
            pq.pop();
            ans += maxNum;
            double ceilNum = maxNum / 3;
            pq.push(ceil(ceilNum));
        }
        return ans;
    }
};