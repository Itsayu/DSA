class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>mr, mm;
        for(int i = 0;i<ransomNote.size(); i++){
            mr[ransomNote[i]]++;
        }
        for(int i = 0; i<magazine.size(); i++){
            mm[magazine[i]]++;
        }
        for(int i = 0; i<ransomNote.size(); i++){
            if(mr[ransomNote[i]]>mm[ransomNote[i]]) 
                return false;
        }
        return true;
    }
};