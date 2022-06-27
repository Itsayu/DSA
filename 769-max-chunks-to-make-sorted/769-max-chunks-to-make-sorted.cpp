class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int large=INT_MIN;
        int ayu=0;
        for(int i=0;i<n;i++) {
            large=max(arr[i],large);
            if(large+1==i+1)
                ayu++;
        }
        return ayu;
    }
};