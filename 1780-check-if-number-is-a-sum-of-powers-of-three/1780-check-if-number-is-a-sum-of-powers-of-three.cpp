class Solution {
public:
    bool checkPowersOfThree(int n){
        // if(n==1){
        //     return true;
        // }
        // if(n%3==0){
        //     return checkPowersOfThree(n/3);
        // }
        // if(n%3==1){
        //     return checkPowersOfThree((n-1)/3);
        // }
        // return false;
        
        
        while(n>0){
            if(n%3==2){
                return false;
            }
            n/=3;
        }
        return true;
    }
};