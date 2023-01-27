class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>st(words.begin(),words.end());
        vector<string>ans;
        for(auto w:words){
            st.erase(w);
            vector<bool>dp(w.size()+1,false);
            dp[0]=true;
            for(int i=1;i<w.size()+1;i++){
                for(int j=0;j<i;j++){
                    string temp=w.substr(j,i-j);
                    if(dp[j] and (st.find(temp)!=st.end())){
                        dp[i]=true;
                        break;
                    }
                }
                
                if(dp.back())ans.push_back(w);
            }
            st.insert(w);
        }
        return ans; 
    }
};