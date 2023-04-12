class Solution {
public:
    string simplifyPath(string str) {
        int n = str.size();        
        string res = "";
        stack<string> st;
        for(int i = 0; i < n; i++){
            if(str[i] == '/')
                continue;
            string temp = "";
            while(i < n && str[i] != '/'){
                temp += str[i];
                i++;
            }
            if(temp == ".")
                continue;
            else if(temp == ".."){
                if(st.empty() == false){
                    st.pop();
                }
            }
            else
                st.push(temp);
        }
        if(st.size() == 0)
            return "/";
        while(st.empty() == false){
            res = "/" + st.top() + res;
            
            st.pop();
        }
        
        return res;
    }
};