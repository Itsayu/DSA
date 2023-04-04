class Solution {
public:
    int partitionString(string s) {
        const int N = s.size();

        int result = 0;
        for (int i = 0; i < N;) {
            int j = i;
            int seen = 0;

            while (j < N && (seen & (1 << (s[j] - 'a'))) == 0) {
                seen ^= (1 << (s[j] - 'a'));
                j++;
            }

            result++;
            i = j;
        }

        return result; 
    }
};