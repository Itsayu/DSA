class Solution {
public:
    const int MOD = 1e9 + 7; 
    vector<long long> memoization; 

    long long calculateOrdersCount(long long remainingPairs) {
        if (remainingPairs == 0)
            return 1;

        if (memoization[remainingPairs] != -1)
            return memoization[remainingPairs];

        long long currentResult = calculateOrdersCount(remainingPairs - 1) * (2 * remainingPairs - 1) * remainingPairs % MOD;
        return memoization[remainingPairs] = currentResult;
    }

    int countOrders(int numPairs) {
        memoization.resize(numPairs + 1, -1);

        return calculateOrdersCount(numPairs);
    }
};