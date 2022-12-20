class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int row = rooms.size(), col = rooms[0].size();
        vector<int> visited(row, 0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int idx = q.front(); q.pop();
            visited[idx] = 1;
            for(int curr: rooms[idx])
                if(!visited[curr])
                    q.push(curr);
        }
        for(int vis: visited)
            if(vis == 0) return false;
        return true;   
    }
};