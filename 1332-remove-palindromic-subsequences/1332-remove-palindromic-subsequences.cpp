class Solution {
public:
    int removePalindromeSub(string s) {
        string r=s;
        reverse(s.begin(),s.end());
        if(r==s){
            return 1;
        }
        else{
        return 2;
        }
    }
};