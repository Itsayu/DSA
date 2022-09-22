class Solution {
public:
    string reverseWords(string s) {
        string ayu="";
        //stringstream is Used for breaking the words
    stringstream nr(s);
        
    string akt="";
    while(getline(nr,akt,' '))
    {
        reverse(akt.begin(),akt.end());
        ayu+=akt;
        ayu+=" ";
    }
    ayu.pop_back();
    return ayu;
    }
};