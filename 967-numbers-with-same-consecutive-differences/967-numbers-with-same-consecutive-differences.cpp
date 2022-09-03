class Solution {
public:
    vector<int>res;
    void func(int n,int k,int num){
        if(n==0){
            res.push_back(num);
            return;
        }
        for(int i=0; i<10; ++i){
            if(i==0 and num==0){
                continue;
            }
            else if(i!=0 and num==0){
                func(n-1,k,i);
            }
            else if(abs(num%10-i)==k){
                func(n-1,k,num*10+i);
            }
        } 
    }
    public:
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n==1){
            res.push_back(0);
        }
        func(n,k,0);
        return res;  
    }
};