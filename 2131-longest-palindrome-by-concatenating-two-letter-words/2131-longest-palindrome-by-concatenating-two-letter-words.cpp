class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mp;
        int ans=0;
        int f=0;
        for (int i=0;i<words.size();i++){
            string s1=words[i];
            reverse(s1.begin(),s1.end());
            if (mp[s1]!=0){
                ans=ans+4;
                mp[s1]--;
            }
            else {
              mp[words[i]]++;
            }
        }
        for (int i=0;i<words.size();i++){
            if ((words[i][0])==(words[i][1])){
                if (mp[words[i]]>0){
                    ans=ans+2;
                    return ans;
                }
            }
        }
        return ans;
    }
};