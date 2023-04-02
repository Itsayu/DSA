class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0;
        int mul=1;
        while(n!=0){
            int rem = n%10;
            mul = mul*rem;
            sum = sum+rem;
            n = n/10;
        }
        return mul-sum;
    }
};