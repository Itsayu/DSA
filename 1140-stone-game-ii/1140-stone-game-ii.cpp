class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        for (int i = n - 2; i >= 0; --i) piles[i] += piles[i + 1];
        return minimax(piles, 0, 1, memo);
    }

    int minimax(vector<int>& piles, int i, int M, vector<vector<int>>& memo) {
        if (i == piles.size()) return 0;
        if (2 * M + i >= piles.size()) return piles[i];
        if (memo[i][M] != -1) return memo[i][M];
        int min_value = INT_MAX;
        for (int X = 1; X <= 2 * M; ++X)
            min_value = min(min_value, minimax(piles, i + X, max(M, X), memo));
        memo[i][M] = piles[i] - min_value;
        return memo[i][M];
    }
};