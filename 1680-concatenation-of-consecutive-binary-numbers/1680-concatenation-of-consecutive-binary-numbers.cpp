class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 1;
        long bc = 2;
        long till = 4;
        long mod = 1000000007;
        for(int i = 2 ; i <= n ; i++){
            ans <<= bc ;
            ans = (ans + i)%mod;
            if(i == till-1){
                till *= 2;
                bc = bc+1;
            }
        }
        return (int)(ans%mod);
    }
};