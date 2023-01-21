class Solution {
public:
    int tonum(string s){
        int num=0;
        for(int i=0;i<s.size();i++){
            num=num*10+(s[i]-48);
        }
        return num;
    }
    vector<string> v;
    void store(string s,int i,string s1,int k){
        if(i>=s.size()){
            if(k==4){
                v.push_back(s1.substr(0,s1.size()-1));
            }
            return;
        }
        if(k>=4) return;
        if(s[i]=='0'){
            string s3=s1;
            s3+="0.";
            store(s,i+1,s3,k+1);
            return;
        }
        for(int j=i;j<i+3;j++){
            if(j<s.size()){
                if(tonum(s.substr(i,j-i+1))<=255){
                    string s2=s1;
                    s2+=s.substr(i,j-i+1);
                    s2+='.';
                    store(s,j+1,s2,k+1);
                }
            }
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        string s1="";
        store(s,0,s1,0);
        return v;
    }
};