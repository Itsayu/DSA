class Solution {
public:
    int calculate(string s) {
        int result=0;
        int sign=1;
        int j=0;
        int len=s.length();
        stack<int> stk;
        while(j<len){ 
            if(s[j]=='+'){
                sign=1;
            }
            else if(s[j]=='-'){
                sign=-1;
            }
            else if(isdigit(s[j])){
                int num=s[j]-'0';
                while(j+1<len && isdigit(s[j+1])){
                    num=num*10+(s[j+1]-'0');
                    j++;
                }
                result+=num*sign;
            }
            else if(s[j]=='('){
                stk.push(result);
                stk.push(sign);
                result=0;
                sign=1;
            }
            else if(s[j]==')'){
                int xsign=stk.top();
                stk.pop();
                int xresult=stk.top();
                stk.pop();
                result=result*xsign + xresult;
            }
            j++;
        }
        return result;
    }
};