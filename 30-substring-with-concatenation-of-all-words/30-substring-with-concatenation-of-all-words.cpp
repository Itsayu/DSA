class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), w = words.size(), wL = words[0].size();
        if(!n || !w)    return {};
        vector<int> ans;
        unordered_map<string,int> freq;
        for(int i=0;i<w;i++)    freq[words[i]]++;
        for(int i=0;i<=n-w*wL;i++)
        {
            unordered_map<string,int>seen;
            for(int j=0;j<w;j++)
            {
                string key = s.substr(i+j*wL,wL);
                if(!freq[key])  break;
                seen[key]++;
                if(seen[key] > freq[key])   break;
                if(j+1 == w)    ans.push_back(i);
            }
        }
        return ans;
    }
};