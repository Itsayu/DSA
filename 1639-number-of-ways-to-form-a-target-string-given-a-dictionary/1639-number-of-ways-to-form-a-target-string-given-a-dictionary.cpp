class Solution {
const int c = 1e9 + 7;
public:
    int numWays(vector<string>& words, string t) {
        unordered_map<char, vector<int>> pos;
        for(int i = 0; i < t.size(); i++) {
            pos[t[i]].push_back(i);
        }
        
        vector<int> lens(t.size(), 0), nlens;
        for(int i = 0; i < words[0].size(); i++) {
            vector<int> v(256, 0);
            for(int j = 0; j < words.size(); j++) {
                v[words[j][i]]++;
            }
            nlens = lens;
            for(auto& x : pos) {
                if(v[x.first] == 0) continue;
                for(int j : x.second) {
                    int pre = j == 0 ? 1 : lens[j-1];
                    nlens[j] = (nlens[j] + 1ll * pre * v[x.first]) % c;
                }
            }
            lens.swap(nlens);
        }
        return lens.back();
    }
};