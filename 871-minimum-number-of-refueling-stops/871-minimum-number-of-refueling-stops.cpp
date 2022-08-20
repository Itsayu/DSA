class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> pq;
        int curr_dist = startFuel;
        int count = 0;
        int i = 0;
        while(curr_dist < target){ 
            while(i < n && stations[i][0] <= curr_dist){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty())
                return -1;
            curr_dist += pq.top();
            pq.pop();
            count++;
        }
        return count;
    }
};