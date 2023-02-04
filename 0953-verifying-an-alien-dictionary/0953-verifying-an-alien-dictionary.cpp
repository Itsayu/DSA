class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> V(26);
        for (int i = 0; i < order.size(); i++) {
            V[order[i]-'a'] = i;
        }

        for (string &word : words) {
            for (char &c : word) {
                c = V[c-'a'] + 'a';
            }
        }
        string cur = "a";
        for (string word : words) {
            if (word >= cur) {
                cur = word;
            }
            else {
                return false;
            }
        }

        return true;  
    }
};