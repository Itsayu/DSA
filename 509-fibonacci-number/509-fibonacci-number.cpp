class Solution {
public:
    int fib(int n) {
        if(n<=1)   
          return n ;  
        int ayu=fib(n-1)+fib(n-2);             
        return ayu;
    }
};