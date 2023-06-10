class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int left = 0, right = maxSum;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (isPossible(mid, index, n, maxSum)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left + 1;
    }
    
    bool isPossible(int a, int index, int n, int sum) {
        long long left = std::max(a - index, 0);
        long long result = (a + left) * (a - left + 1) / 2;
        long long right = std::max(a - ((n - 1) - index), 0);
        result += (a + right) * (a - right + 1) / 2;
        return (result - a <= sum);
    }
};