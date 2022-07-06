class Solution {
public:
    int fib(int n) {
        if(n <= 1)                                     // if n == 0 or n == 1 
          return n ;                                // return number 
        int output = fib(n-1)+fib(n-2);            // used recursion to call the function   
        return output ;
    }
};