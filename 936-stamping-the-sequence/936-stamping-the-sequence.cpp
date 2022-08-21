class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> revans;
        vector<bool> visited(target.size(),false);
        int count=0;
        while(count!=target.size()){
            bool changed=false;
            for(int i=0;i<=target.size()-stamp.size();i++){
                if(!visited[i] && isAvailable(stamp,target,i)){
                    count+=replace(stamp.size(),target,i);
                    visited[i]=true;
                    revans.push_back(i);
                    changed=true;
                    if(count==target.size())break;
                }
            }
            if(!changed)return {};
        }
        vector<int>ans;
        for(int i=revans.size()-1;i>=0;i--){
            ans.push_back(revans[i]);
        }
        return ans;
    }
    bool isAvailable(string stamp,string target,int i){
        for(int j=0;j<stamp.size();j++){
            if(target[j+i]!='?' && target[j+i]!=stamp[j]){
                return false;
            }
        }
        return true;
    }
    int replace(int m,string& target,int i){
        int count=0;
        for(int j=0;j<m;j++){
            if(target[i+j]!='?'){
                target[i+j]='?';
                count++;
            }
        }
        return count;
    }
};