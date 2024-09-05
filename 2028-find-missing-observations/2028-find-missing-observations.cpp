class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(int r:rolls){
            sum += r;
        } 

        int expectedSum = mean*(n+m);
        int missSum = expectedSum - sum;
        if(missSum<n || missSum>6*n) {
            return {};
        }

        vector<int> ans(n, 1);
        missSum -= n;
        for(int i = 0; i<n; i++){
            int add = min(missSum, 5);
            ans[i] += add;
            missSum -= add;
        }
        return ans;
    }
};