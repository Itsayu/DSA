class Solution {
public:
    void solve(const string& s, int ind, const unordered_set<string>& wordSet, string& curr, vector<string>& result) {
        if (ind == s.length()) {
            result.push_back(curr);
            return;
        }

        for (int end = ind + 1; end <= s.length(); ++end) {
            string word = s.substr(ind, end - ind);

            if (wordSet.find(word) != wordSet.end()) {
                string prev = curr.empty() ? word : (curr + " " + word);
                solve(s, end, wordSet, prev, result);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> ans;

        string curr;

        solve(s, 0, wordSet, curr, ans);

        return ans;
    }
};