class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int patternLength = pattern.size();
        
        vector<string> result;
        unordered_map<char, char> um;
        unordered_map<char, char> um1;
        
        for(int i=0; i<words.size(); i++){
            int j;
            for(j=0; j<patternLength; j++){
                if(um.find(pattern[j]) != um.end()){
                    if( um[pattern[j]] != words[i][j])
                        break;
                }
                if(um1.find(words[i][j]) != um1.end()){
                    if( um1[words[i][j]] != pattern[j] )
                        break;
                }
                else{
                    um[pattern[j]] = words[i][j];
                    um1[words[i][j]] = pattern[j];
                }
            }
            
            if( j == patternLength)
                result.push_back(words[i]);
            
            um.clear();
            um1.clear();
        }
        
        return result;
    }
};