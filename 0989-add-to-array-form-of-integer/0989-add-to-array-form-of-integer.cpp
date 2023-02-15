class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        for(int i=0;i<num.size();i++){
            int sum = num[i]+k;
            int dig = sum%10;
            k = sum/10;
            num[i]=dig;
        }
        while(k>0){
            int dig = k%10;
            num.push_back(dig);
            k/=10;
        }
        reverse(num.begin(), num.end());
        return num;
    }
};