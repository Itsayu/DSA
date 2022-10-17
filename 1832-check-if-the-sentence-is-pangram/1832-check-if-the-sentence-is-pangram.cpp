class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>v(26,0);
        for(auto it: sentence){
            v[it-'a']=1;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]==0)return false;
        }
        return true;
    }
};