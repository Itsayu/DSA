class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        string res;
        for(char c: s){
            res.append(to_string((int)c-97+1));
        }
        for(int i=0;i<k;i++){
            for(char c: res){
                sum+=(int)c-48;
            }
            res.clear();
            res.append(to_string(sum));
            sum=0;
        }

        return stoi(res);
    }
};