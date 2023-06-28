class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    map<pair<int, int>, double> track;
    for (int i = 0; i < edges.size(); ++i)
    {
        track[{edges[i][0], edges[i][1]}] = succProb[i];
        track[{edges[i][1], edges[i][0]}] = succProb[i];
    }
    vector<int> adj[n];
    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    set<pair<double, int>> q;
    q.insert({1.0, start});
    vector<double> prob(n, 0.0);
    prob[start] = 1.0;
    while (q.size() > 0)
    {
        auto currPair = (*--q.end());
        q.erase(--q.end());
        int currVertex=currPair.second;
        for (auto adjacentVertex : adj[currVertex])
        {
            double edgeProbability = track[{currVertex, adjacentVertex}];
            if (prob[adjacentVertex] < prob[currVertex] * edgeProbability)
            {
                prob[adjacentVertex] = prob[currVertex] * edgeProbability;
                q.insert({prob[adjacentVertex], adjacentVertex});
            }
        }
    }
    return prob[end] == 0.0 ? 0 : prob[end]; 
    }
};