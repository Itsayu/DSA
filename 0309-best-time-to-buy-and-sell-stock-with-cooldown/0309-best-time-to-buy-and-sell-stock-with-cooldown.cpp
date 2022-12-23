class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, sell = 0, cooldown = 0;
        for (auto price : prices) {
            int prev_buy = buy, prev_sell = sell, prev_cooldown = cooldown;
            buy = max(prev_buy, prev_cooldown - price);
            sell = prev_buy + price;
            cooldown = max(prev_sell, prev_cooldown);
        }
        return max(sell, cooldown);
    }
};