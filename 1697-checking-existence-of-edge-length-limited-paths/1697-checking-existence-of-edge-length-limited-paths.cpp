class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& E, vector<vector<int>>& Q) {
        sort(begin(E), end(E), [](auto &a, auto & b) {return a[2] < b[2];});

        for(int i = 0; i < Q.size(); i++) Q[i].push_back(i);
        sort(begin(Q), end(Q), [](auto &a, auto & b) {return a[2] < b[2];});
        
        vector<int> root(n);
        for(int i = 0; i < n; i++) root[i] = i;

        auto findP = [&] (int t) {
            while(t != root[t]) {
                root[t] = root[root[t]];
                t = root[t];
            }
            return t;
        };

        int idx = 0;
        vector<bool> res(Q.size());
        for(auto & q : Q) {
            int d = q[2];
            while(idx < E.size() && E[idx][2] < d) {
                int p1 = findP(E[idx][0]), p2 = findP(E[idx][1]);
                if(p1 != p2) root[p1] = p2;
                idx++;
            }
            res[q[3]] = findP(q[0]) == findP(q[1]);
        }
        return res;
    }
};