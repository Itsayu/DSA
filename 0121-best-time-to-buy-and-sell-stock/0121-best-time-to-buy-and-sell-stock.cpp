class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result=0, minVal = INT_MAX;
        int soldToday = -1;
        for(int i=0; i<prices.size(); i++){
            minVal = min(prices[i], minVal);
            soldToday = prices[i]-minVal;
            result = max(result, soldToday);
        }     
        return result;
    }
};