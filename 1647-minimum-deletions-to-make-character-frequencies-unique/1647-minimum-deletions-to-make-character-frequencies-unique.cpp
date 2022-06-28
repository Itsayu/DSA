class Solution {
public:
    int minDeletions(string s) {
        int ayu=0;
        unordered_map<char,int> map;
        priority_queue<int> q;
        for(auto x:s){
            map[x]++;
        }
        for(auto m:map){
            q.push(m.second);
        }
        while(q.size()>0){
            int x=q.top();
            q.pop();
            if(q.size()>0 && x==q.top()){
                ayu++;
                if(--x>0){
                    q.push(x);
                }
            } 
        }
        return ayu;
    }
};