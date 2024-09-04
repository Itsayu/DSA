class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> cordinate = {0,0};
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        int face = 0;
        int distant = 0;
        for(int &x:commands){
            if(x==-1){
                face++;
                face%=4;
            }else if(x==-2){
                face+=3;
                face%=4;
            }else{
                vector<int> blocks;
                for(int i=0;i<2;++i){
                    if(directions[face][i]==0){
                        for(auto &x:obstacles){
                            if(x[i]==cordinate[i]){
                                blocks.push_back(x[(i+1)%2]);
                            }
                        }
                    }
                }
                sort(blocks.begin(),blocks.end());
                for(int i=0;i<2;++i){
                    if(directions[face][i]==1){
                        auto b = upper_bound(blocks.begin(),blocks.end(),cordinate[i]);
                        if(b != blocks.end()){
                            cordinate[i] = min(cordinate[i]+x,*b-1);
                        }else{
                            cordinate[i] += x;
                        }
                    }else if(directions[face][i]==-1){
                        auto b = lower_bound(blocks.begin(),blocks.end(),cordinate[i]);
                        if(b != blocks.begin()){
                            cordinate[i] = max(cordinate[i]-x,*(b-1)+1);
                        }else{
                            cordinate[i] -= x;
                        }
                    }
                    distant = max(distant, cordinate[0]*cordinate[0]+cordinate[1]*cordinate[1]);
                }
            }
        }

        return distant;
    }
};