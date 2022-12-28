class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> hp;
        int res = 0 ; 
        for( auto x : piles) {   
            res += x;
            hp.push(x);
        }
        while( k--){
            int x = hp.top();
            hp.pop();
            hp.push(x-x/2);
            res -= x/2;
        } 
        return res;   
    }
};