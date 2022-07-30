class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> wv2(26, 0);
        for(string s: words2) {
            vector<int> v(26, 0);
            for(char c: s) {
                v[c-'a']++;
            }
            for(int i=0; i<26; i++) {
                wv2[i] = max(wv2[i], v[i]);
            }
        }
        vector<string> res;
        for(string s: words1) {
            vector<int> v(26, 0);
            for(char c: s) {
                v[c-'a']++;
            }
            int i;
            for(i=0; i<26; i++) {
                if(v[i] < wv2[i])
                    break;
            }
            if(i==26)
                res.push_back(s);
        }
        return res;
    }
};