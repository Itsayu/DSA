class Solution {
public:
    long maxRunTime(int n, vector<int>& batteries) {
        long sumPower = 0;
        for (int power : batteries)
            sumPower += power;
        long left = 1, right = sumPower / n;
        
        while (left < right) {
            long time = (left + right + 1) / 2;
            if (check(batteries, n, time))
                left = time;
            else
                right = time - 1;
        }
        return left;
    }
    
    bool check(vector<int>& B, int n, long time) {
        long sum = 0;
        for (int battery : B) {
            sum += min(static_cast<long>(battery), time);
        }
        return (sum >= static_cast<long>(time) * n);
    }
};