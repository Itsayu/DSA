class Solution {
public:
    string countOfAtoms(string s) {
        stack<pair<string, int>> st; 
        stack<int> fact;
        int n = s.length(), m = 1, val = 1;

        for(int i = n - 1; i >= 0; i--){
            char ch = s[i];
            // ch --> lowercase letter
            if(ch >= 'a' && ch <= 'z'){
                string element = "";
                while(!(s[i] >= 'A' && s[i] <= 'Z')){
                    element = s[i] + element;
                    i--;
                }
                element = s[i] + element;
                int freq = m*val;
                st.push({element, freq});
                val = 1;
            }
            // ch --> uppercase letter
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                string element = "";
                element += s[i];
                int freq = m*val;
                st.push({element, freq});
                val = 1;
            }
            else if(ch == ')'){
                fact.push(val);
                m *= val;
                val = 1;
            }
            else if(ch == '('){
                m /= fact.top();
                fact.pop();
            }
            else{
                string num = "";
                while(s[i] <= '9' && s[i] >= '0'){
                    num = s[i] + num;
                    i--;
                }
                i++; 
                val = stoi(num);
            }
        }
        
        map<string, int> mp;
        while(! st.empty()){
            auto it = st.top(); st.pop();
            string str = it.first;
            int freq = it.second;
            mp[str] += freq;
        }
        string res = "";
        for(auto it : mp){
            string ele = it.first;
            string freq = "";
            if(it.second != 1) freq += to_string(it.second);
            res += ele + freq;
        }
        return res; 
    }
};