class Solution {
public:
    using int2=pair<int, int>; // (difficulty[i], profit[i])
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int n=profit.size(), m=worker.size();
        vector<int2> d_p(n);
        for(int i=0; i<n; i++) 
            d_p[i]={difficulty[i], profit[i]};

        sort(d_p.begin(), d_p.end());
        sort(worker.begin(), worker.end());
        
        int maxProfit=0,  idx=0, bestProfit = 0;

        for (int i = 0; i < m; i++) {
            // Increase index to the next worker's ability
            while (idx < n && worker[i] >= d_p[idx].first) {
                bestProfit = max(bestProfit, d_p[idx].second);
                idx++;
            }
            maxProfit+= bestProfit;
        }
        return maxProfit;
    }
};