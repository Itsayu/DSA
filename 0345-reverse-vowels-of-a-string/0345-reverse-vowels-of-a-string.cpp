class Solution {
public:
    bool isVowel(char ch){
        char currCh = tolower(ch); 
        if (currCh == 'a' || currCh == 'e' || currCh == 'i' || currCh == 'o' || currCh == 'u')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int n = s.size();
        int low = 0, high = n - 1;
        while(low < high){
            bool isLowVowel = isVowel(s[low]);
            bool isHighVowel = isVowel(s[high]);
            if (isLowVowel && isHighVowel){
                swap(s[low], s[high]);
                low++; high--;
            }
            else if (!isLowVowel) low++; 
            else if (!isHighVowel) high--; 
        }
        return s;    
    }
};