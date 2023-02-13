class Solution {
public:
    int countOdds(int low, int high) {
        int ans= (high-low)/2;
        if (low&1 || high&1)
            ans++;
        return ans;  
    }
};