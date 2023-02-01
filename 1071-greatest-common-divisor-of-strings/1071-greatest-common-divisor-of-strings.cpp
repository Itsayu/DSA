class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n =str1.length(),m=str2.length();
        int g = __gcd(n,m);
        
        return str1+str2==str2+str1?str1.substr(0,g):"";
    }
};