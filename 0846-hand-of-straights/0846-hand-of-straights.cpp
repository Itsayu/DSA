class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int nr = hand.size();
        sort(hand.begin(),hand.end());
        unordered_map<int,int> mp;
        for(auto it: hand){
            mp[it]++;
        }
        for(int i=0;i<nr;i++){
            if(mp[hand[i]] == 0){
                continue;
            }
            int st = hand[i];
            int count= 1;
            while(count<=groupSize){
                if(mp[st]==0){
                    return false;
                }
                mp[st]--;
                st++;
                count++;
            }
        }
        return true;
    }
};