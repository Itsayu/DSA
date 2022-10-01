class Solution {
public:
    int solve(string &s, vector<int> &data, int idx) {
        if(idx == s.size()) return 1;
        if(data[idx] != -1) return data[idx];
        if(s[idx] == '0') return data[idx] = 0;
        int res = solve(s, data, idx+1);
        if(s[idx] < '3' && idx < s.size() - 1 && (s[idx] < '2' || s[idx+1] < '7')) {
            res += solve(s, data, idx+2);
        }
        return data[idx] = res;
    }
    int numDecodings(string s) {
        vector<int> data(s.size(), -1);
        return solve(s, data, 0);    
    }
};