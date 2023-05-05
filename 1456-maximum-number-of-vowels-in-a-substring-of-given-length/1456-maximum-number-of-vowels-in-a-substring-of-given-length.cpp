class Solution {
public:
    bool isvowel(char c){
        return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
    }
    int maxVowels(string s, int k) {
        int i=0;
        int j=0;
        int n=s.size();
        int len=0;
        int ctv=0;
        int res=0;
		//Code starts
        while(j<n){
            if(isvowel(s[j])){
                ctv++;
            }
            len++;
            if(len>k){
                if(isvowel(s[i])){
                    ctv--;
                }
                i++;
            }
            res=max(res,ctv);
            j++;
        }
        return res; 
    }
};