class Solution {
public:
    bool validateStackSequences(vector<int>& push, vector<int>& pop) {
        stack<int> s;
        for(int i=0, j=0; i<push.size(); ++i){
            s.push(push[i]);
            while(!s.empty() && s.top()==pop[j]){
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};