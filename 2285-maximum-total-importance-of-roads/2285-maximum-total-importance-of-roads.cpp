class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // Vector to keep track of the degree of each node
        vector<long long> degree(n, 0);

        // Calculate the degree of each node by traversing the roads
        for (int i = 0; i < roads.size(); i++) {
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }

        // Sort the degree vector
        sort(degree.begin(), degree.end());

        // Calculate the maximum importance by assigning the highest values to the highest degrees
        long long importance = 0;
        for (long long i = 0; i < n; i++) {
            importance += (i + 1) * degree[i];
        }

        return importance;
    }
};