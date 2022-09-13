class Solution {
public:
    string utf(int n){
        string ans="";
        while(n>0){
            if(n&1){
                ans+="1";
            }
            else{
                ans+="0";
            }
            n=n>>1;
        }
        while(ans.length()<8){
            ans+="0";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    bool check(string s){
        if(s[0]=='1' and s[1]=='0')return true;
        return false;
    }
    bool validUtf8(vector<int>& data) {
        vector<string>vec;
        for(auto x:data){
            vec.push_back(utf(x));
        }
       int i=0;
        while(i<vec.size()){
            string temp=vec[i];
            if(temp[0]=='0'){
                i++;
                continue;
            }
            int cnt=0;
            for(int j=0;j<temp.size();j++){
                if(temp[j]=='1'){
                    cnt++;
                    
                }
                else{
                    break;
                }
            }
            if(cnt>4 or cnt==1){
                cout<<i<<" 1"<<cnt;
                return false;
            }
            for(int k=1;k<=cnt-1;k++){
                if(check(vec[i+k])==false){
                    cout<<i<<" 2"<<endl;
                    return false;
                }
            }
            i+=cnt;
        }
        return true;   
    }
};