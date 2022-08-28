class Solution {
public:
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> diagonally;
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {    
        int numRow = mat.size();
        int numCol = mat[0].size();
        
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
                diagonally[i - j].push(mat[i][j]);
            }
        }
        
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
                mat[i][j] = diagonally[i - j].top();
                diagonally[i - j].pop();
            }
        }
        
        return mat;  
    }
};