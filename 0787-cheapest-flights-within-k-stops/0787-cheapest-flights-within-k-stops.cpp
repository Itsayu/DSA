class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <int> distance(n ,INT_MAX);
        distance[src] = 0;
        for(int i = 0 ; i < k + 1; i ++){
            vector <int> copy(distance);
            for(auto flight : flights){
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];             
                if(distance[u] != INT_MAX and (distance[u] + w < copy[v])){
                    copy[v] = distance[u] + w;
                }
            }
            distance = copy;
        }
        return (distance[dst] == INT_MAX ? -1 : distance[dst]);
    }
};