class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> f1(26,0);  //freq array for string s
        vector<int> f2(26,0);  //freq array for string p
        for(char x:p) f2[x-'a']++;
        
        int i=0,j=p.size()-1;
        for(int ii=0;ii<s.size() && ii<=j;ii++) f1[s[ii]-'a']++;
        
        vector<int> ans;
        if(f1==f2)ans.push_back(i);
        
        while(j< s.size()-1){
            f1[(int)(s[i++]-'a')]--;
            f1[(int)(s[++j]-'a')]++;
            if(f1==f2)ans.push_back(i);
        }
        
        return ans;
    }
};