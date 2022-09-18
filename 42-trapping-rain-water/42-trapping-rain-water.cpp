class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int res = 0;
        for(int i =0;i<n;i++){
            while(!st.empty() and height[st.top()] < height[i]){
              int curr = st.top();
              st.pop();
              if(st.empty())break;
               int diff = i-st.top()-1;
               res+=(min(height[st.top()],height[i])-height[curr])*diff;
            }
            st.push(i);
        }
        
        return res;   
    }
};