class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        unordered_set<string> st;
        for(int i=0;i<strs.size();i++){
            st.insert(strs[i]);
        }
        int cnt = 0;
        for(int i=0;i<strs.size();i++){
            if(st.find(strs[i])!=st.end()){
                cnt++;
                queue<string> q;
                q.push(strs[i]);
                st.erase(strs[i]);
                while(!q.empty()){
                    string s = q.front();
                    q.pop();
                    st.erase(s);
                    for(auto &it : st){
                        int c = 0;
                        for(int i=0;i<it.size();i++){
                            if(it[i]!=s[i]) c++;
                        }
                        if(c==2){
                            q.push(it);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};