class Solution {
public:
    string orderlyQueue(string nr, int K) {
        if(K > 1) {
            sort(nr.begin(), nr.end());
            return nr;
        }
        
        int n = nr.size();
        string res = nr;
        nr += nr;
        for(int i=0;i<n;i++) {
            if(nr.substr(i, n) < res) res = nr.substr(i, n);
        }
        return res;   
    }
};