class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int len = words.size();
        vector<string> ans;
        unordered_map<char, array<int,100>> mp;
        for(int i=0;i<len;i++){
            for(int j=0;j<words[i].size();j++) 
                mp[words[i][j]][i]++; 
        }
        int cnt=0;
        for(auto x:mp) {
            cnt = INT_MAX;
            for(int i=0;i<len;i++) {
                if(x.second[i]< cnt)
                    cnt = x.second[i];  
            }
            string s(1, x.first);
            for(int i=0;i<cnt;i++)
                ans.push_back(s);
        }
        return ans;
        
    }
};