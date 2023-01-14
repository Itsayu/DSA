class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        char map[26];
        for(int i=0;i<26;i++){
            map[i] = i+'a';
        }
        for(int i=0;i<s1.size();i++){
            char replace = max(map[s1[i] - 'a'],map[s2[i] - 'a']); //Bigger element
            char put = min(map[s1[i] - 'a'],map[s2[i] - 'a']); // Smaller element
            for(int i=0;i<26;i++){
                if(map[i] == replace)
                    map[i] = put;   // Replace all the bigger characters with it's smallest equivalent
            }
        }

        string ans = "";
        for(int i=0;i<baseStr.size();i++){
            ans += map[baseStr[i] - 'a'];
        }
        return ans;   
    }
};