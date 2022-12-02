class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int len=word1.length();
        if(word2.length()!=len)
            return false;
        
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        for(int i=0;i<len;i++){
            count1[word1[i]-'a']++;
            count2[word2[i]-'a']++;
        }
        //Checking if same characters exist
        for(int i=0;i<26;i++){
            if((count1[i]>0 && count2[i]==0) || (count1[i]==0 && count2[i]>0))
                return false;
        }
        sort(begin(count1),end(count1));
        sort(begin(count2),end(count2));
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i])
                return false;
        }
        return true; 
    }
};