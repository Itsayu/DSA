class Solution {
public:
    int reverse(int x) {
        int nr  = 0;
        while( x != 0) {
            int digit = x % 10;
            if( (nr > INT_MAX/10) || (nr < INT_MIN/10)) {
                return 0;
            }
            nr = (nr * 10) + digit;
            x = x / 10;
        }  
        return nr;
    }

};
