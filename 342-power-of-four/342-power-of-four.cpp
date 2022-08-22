class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        int count=0, i=0;
            while(n!=0){
                if((n&1) == 1){                                 
                    count++;
                    if(i%2!=0) return false;
                }
                if(count>1) return false;  
                n=n>>1;
                i++;
            }
        return true;
    }
};