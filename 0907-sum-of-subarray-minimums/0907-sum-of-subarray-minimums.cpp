class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
		long n=arr.size();
		vector<int> left(n),right(n);
		stack<pair<int,int>> st1;
		stack<pair<int,int>> st2;
		int count;
		for(int i=0;i<n;i++){
			count=1;
			while(!st1.empty() && st1.top().first>arr[i]){
				count+=st1.top().second;
				st1.pop();
			}
			st1.push({arr[i],count});
			left[i]=count;
		}
		for(int i=n-1;i>=0;i--){
			count=1;
			while(!st2.empty() && st2.top().first>=arr[i]){
				count+=st2.top().second;
				st2.pop();
			}
			st2.push({arr[i],count});
			right[i]=count;
		}
		long res=0,m=1e9 +7;
		for(int i=0;i<n;i++){
			res=(res+(long)arr[i]*left[i]*right[i])%m;
		}
		return res;  
    }
};