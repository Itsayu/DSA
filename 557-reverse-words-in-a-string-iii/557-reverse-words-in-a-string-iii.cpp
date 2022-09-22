class Solution {
public:
    string reverseWords(string s) {
        string sol="";
    stringstream ss(s);
    
    string str = "";
    while(getline(ss,str,' '))
    {
        reverse(str.begin(),str.end());
        sol+=str;
        sol+=" ";
    }
    sol.pop_back();
    return sol;
    }
};