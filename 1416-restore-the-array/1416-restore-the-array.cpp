class Solution {
public:
    int numberOfArrays(string s, int k) {
        int N = s.size();
        vector<long> nr(N + 1, 0);
        nr[N] = 1;
        
        for (int i = N - 1; i >= 0; i--) {
            long sum = 0;
            for (int j = i; j < N; j++) {
                sum *= 10;
                sum += s[j] - '0';
                if (sum > k || sum == 0) {
                    break;
                }
                else {
                    nr[i] += nr[j + 1];
                }
            }
            nr[i] %= 1000000007;
        }

        return nr[0];
    }
};