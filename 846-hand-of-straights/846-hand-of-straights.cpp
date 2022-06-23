class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         if(hand.size() % groupSize != 0) return false;
         map<int,int>table;
         for(auto x:hand)
             table[x]++;
         for(auto[x,n]:table)
         while(n--)
         for(int i=1;i!=groupSize;i++)
            if(!table.count(x+i)||table[x+i]-- == 0) return false;
      
         return true; 
    }
};