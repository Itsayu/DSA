class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp1;
        unordered_map<string,bool> mp2;
        
        stringstream ss(s);
        vector<string> v;
        string a;
        while(getline(ss, a, ' '))
        {
            v.push_back(a);
        }
        if(v.size()!=pattern.size())
        {
           return false;
        }

        
        for(int i=0; i<pattern.size(); i++)
        {
             if(mp1.find(pattern[i])!= mp1.end())
             {
                 char a= pattern[i];
                 if(mp1[a]!= v[i])
                 {
                     return false;
                 }
             }
            else
            { 
                if(mp2.find(v[i])!= mp2.end())
                 {
                      return false;
                 }
                else
                {
                    mp1[pattern[i]]= v[i];
                    mp2[v[i]]= true;
                }
            }
        }
        return true;
    }
};