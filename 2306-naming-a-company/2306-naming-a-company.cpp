class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        unordered_set<string> idea;
        for(int i=0; i<n; i++)
            idea.insert(ideas[i]);
        
        vector<vector<int>> count(26, vector<int>(26));
        
        for(int i=0; i<n; i++){
            string temp = ideas[i];
            int s = ideas[i][0]-'a';
            for(int j=0; j<26; j++){
                temp[0] = j+'a';
                if(idea.find(temp) == idea.end()){
                    count[s][j]++;
                }
            }
        }
        
        long long res = 0;
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                res += count[i][j]*count[j][i];
            }
        }
        
        return res; 
    }
};