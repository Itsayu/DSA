class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans=0, i, j, pos;
        string str;
        sort(words.begin(), words.end(), [](const string &s1, const string &s2){
            return s1.size() > s2.size();
            });
        
        ans = words[0].size()+1;
        str = words[0]+"#";
        for(i=1; i<words.size(); i++){
            if(str.find(words[i]+"#") == -1)      
                str = str.append(words[i]+"#");
        }
        return str.size(); 
    }
};