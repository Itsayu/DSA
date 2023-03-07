class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1;
        long long r = *min_element(time.begin(), time.end()) * (long long) totalTrips;

        while (l < r) {
            long long m = (l + r) / 2;
            if (numTrips(time, m) >= totalTrips)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

    long long numTrips(vector<int>& time, long long m) {
        long long num = 0;
        for (int t : time) {
            num += m / t;
        }
        return num;
    }
};