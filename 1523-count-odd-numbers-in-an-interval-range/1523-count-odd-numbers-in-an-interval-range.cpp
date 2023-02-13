class Solution {
public:
    int countOdds(int low, int high) {
        int nr = (high - low)/2;
        if (low & 1 || high & 1)
            nr++;
        return nr;  
    }
};