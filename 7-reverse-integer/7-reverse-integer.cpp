class Solution {
public:
    int reverse(int x) {
        int ayu=0;
        while(x!=0){
            int digit= x%10;
            if((ayu>INT_MAX/10)||(ayu<INT_MIN/10)){
                return 0;
            }
            ayu=(ayu *10)+digit;
            x/=10;
        }
        return ayu;
    }
};