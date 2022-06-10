class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        int ayu=0;
        unordered_set<char>Set;
        while(i<n && j<n){
            if(Set.find(s[j])==Set.end()){
                Set.insert(s[j]);
                j++;
                ayu=max(ayu,j-i);
                }
            else{
                Set.erase(s[i]);
                i++;
            }
        }
        return ayu;
    }
};