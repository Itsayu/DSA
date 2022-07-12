class Solution {
public:
    vector<int> sides = {0, 0, 0, 0};
    bool dfs(vector<int>& arr, int i, int n, int target)
    {
        if(i>=n){
            return true;
        }
        for(int j=0;j<4;j++){
            if(sides[j]+arr[i]<=target){
                sides[j]+=arr[i];
                if(dfs(arr,i+1,n,target)){
                    return true;
                }
                sides[j]-=arr[i];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum % 4){
            return false;
        }
        int target=sum/4;
        sort(arr.begin(),arr.end(),greater<int>());
        return dfs(arr, 0, n, target);
    }
};