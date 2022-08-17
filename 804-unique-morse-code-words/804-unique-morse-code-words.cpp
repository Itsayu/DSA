class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        vector<string>sst;
        for(auto x:words)
        {
            string store;
            for(auto ch:x)
            {
                store+=morse[ch-'0'-49];
            }
            sst.push_back(store);
        }
        map<string,int>m;
        for(auto x:sst)
        {
            m[x]++;
        }
        return m.size();
    }
};