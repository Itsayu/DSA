class Solution {
public:
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        if (m != n) return false;
        if (m == 0 && n == 0) return true;
        
        return solve(s1, s2);
    }
    
    bool solve(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        bool flag = false;
        
        if (s1 == s2) return true;
        if (n <= 1) return false;
        
        string key = s1 + ' ' + s2;
        if (mp.count(key) > 0) {
            return mp[key];
        }
        
        for (int i = 1; i <= n - 1; i++) {     
            bool con1 = (solve(s1.substr(0, i), s2.substr(n - i, i)) == true && solve(s1.substr(i, n - i), s2.substr(0, n - i)) == true);
            
            bool con2 = (solve(s1.substr(0, i), s2.substr(0, i)) == true && solve(s1.substr(i, n - i), s2.substr(i, n - i)) == true);
            
            if (con1 || con2) {
                flag = true;
                break;
            }
        }
        
        return mp[key] = flag;
    }
};