class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long org = x;
        long rev = 0;
        while(x != 0){
            int rem = x % 10;
            rev = (rev * 10) + rem;
            x /= 10;
        }
        return org == rev;
    }
};
