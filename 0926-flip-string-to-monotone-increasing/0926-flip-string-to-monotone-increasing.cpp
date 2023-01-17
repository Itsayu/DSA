class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count1=0;
        int flips=0;
        for(auto x:s){
            if(x=='1')count1++;
            else{
             flips=min(++flips,count1);
            }   
        }
        return flips;
    }
};