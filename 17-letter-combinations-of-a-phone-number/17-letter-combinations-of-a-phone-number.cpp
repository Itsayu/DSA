class Solution {
private: 
    void solve(string digit, string output, int index, vector<string> &nr, string mapping[]){
        if(index >= digit.length()){
            nr.push_back(output);
            return;
        }
        int number = digit[index]-'0';
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(digit, output, index+1, nr, mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ayu;
        if (digits.length()==0){
            return ayu;
        }
        string output;
        int index = 0;
        string mapping[10]={"", "", "abc", "def","ghi", "jkl", "mno","pqrs","tuv", "wxyz"};
        solve(digits, output, index, ayu, mapping);
        return ayu;
    }
};