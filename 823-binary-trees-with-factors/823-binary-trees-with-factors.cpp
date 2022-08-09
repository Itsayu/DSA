class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int mod = 1000000007;
        vector<long long> dp(n, 1);
        unordered_set<int> st;
        for(int i: arr)
            st.insert(i);
        unordered_map<int, int> index;
        for(int i=0; i<n; i++) 
            index[arr[i]] = i;
        
        for(int i=1; i<n; i++){
            int num=arr[i];
            int srt = sqrt(num);
            for(int j=0; j<i; j++){
                int num2 = arr[j];
                if(num2>srt)
                    break;
                int num3 = num/num2;
                if(num%num2 == 0 && st.find(num3)!=st.end()){
                    dp[i] = (dp[i] + 2*(dp[j]*dp[index[num3]]))%mod;
                    if(num2*num2 == num)   
                        dp[i] = (dp[i] - (dp[j]*dp[index[num3]]))%mod;
                }
            }
        }
        int sum=0;
        for(int i: dp)
            sum = (sum + i)%mod;
        return sum;
        
    }
};