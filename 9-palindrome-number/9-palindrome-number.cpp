class Solution {
public:
    bool isPalindrome(int x){
        if(x<0){
            return false;
        }
        long num=0;
        int ayu=x;    
        int akt=0;
        while(ayu){
            akt=ayu%10;                  
            num=num*10+akt;
            ayu/=10;                    
        }
        if(num==x){    
            return true;
        }
        else{ 
            return false;
        }
    }
};