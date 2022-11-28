class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        int n=mat.size();
        unordered_map<int,int> nr,akt;
        for(int i=0;i<n;i++){
            nr[mat[i][0]]=1;
            akt[mat[i][1]]++;
        }
        for(int i=0;i<n;i++){
            int x=mat[i][1];
            if(nr.find(x)!=akt.end()){
                nr[x]=0;
            }
        }
        vector<vector<int>> nrakt;
        vector<int> r,t;
        for(auto x:nr){
            if(x.second==1){
                r.push_back(x.first);
            }
        }
        for(auto x:akt){
            if(x.second==1){
                t.push_back(x.first);
            }
        }
        sort(r.begin(),r.end());
        sort(t.begin(),t.end());
        nrakt.push_back(r);
        nrakt.push_back(t);
        return nrakt;   
    }
};