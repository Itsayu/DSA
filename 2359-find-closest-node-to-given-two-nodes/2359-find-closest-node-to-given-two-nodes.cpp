class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);
        vector<bool> vis1(n, false);
        vector<bool> vis2(n, false);
        
        int curNode = node1;
        int curDist = 0;
        while(curNode!=-1 && vis1[curNode] == false) {
            vis1[curNode] = true;
            dist1[curNode] = curDist;
            curNode = edges[curNode];
            curDist++;
        }
        curNode = node2;
        curDist = 0;
        while(curNode!=-1 && vis2[curNode] == false) {
            vis2[curNode] = true;
            dist2[curNode] = curDist;
            curNode = edges[curNode];
            curDist++;
        }
        int minDist = INT_MAX;
        int index = -1;
        for(int i=0;i<n;i++) {
            if(dist1[i] != -1 && dist2[i]!=-1) {
                int maxDist = max(dist1[i], dist2[i]);
                if(maxDist < minDist) {
                    minDist = maxDist;
                    index = i;
                }
            }
        }
        
        return index;   
    }
};