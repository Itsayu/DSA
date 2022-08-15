class Solution {
public:
    int fun(const char a)
{
    if(a == 'I') return 1;
    if(a == 'V') return 5;
    if(a == 'X') return 10;
    if(a == 'L') return 50;
    if(a == 'C') return 100;
    if(a == 'D') return 500;
    if(a == 'M') return 1000;
    
    return 0;
}
int romanToInt(string s) 
{
    int res = 0;
    
    
    for(int i = 0; i < s.size(); i++)
    {
        if ((fun(s[i]) < fun(s[i+1])))
        {
            res -= fun(s[i]);
        }
        else
        {
            res += fun(s[i]);
        }
    } 
    return res;
}
};