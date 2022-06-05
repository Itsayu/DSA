class Solution {
private:

    vector<vector<bool>> board;
    set<string> ans;
    int N;
    
    bool checker(int x, int y){
        for(int i=x-1;i>=0;i--)
            if(board[i][y]) return false;
        for(int i=x-1, j=y+1; i>=0 and j<N; i--, j++)
            if(board[i][j]) return false;
        for(int i=x-1, j=y-1; i>=0 and j>=0; i--, j--)
            if(board[i][j]) return false;
        return true;
    }
    
    void save_output(){
        string v;
        for(int i=0;i<N;i++){
            string s;
            for(int j=0;j<N;j++)
                s += board[i][j] ? "Q": ".";
            v += s;
        }
        ans.insert(v);
    }
    
    
    void nq_helper(int row){
        if(row == N){
            save_output();
            return;
        }
        for(int i=0;i<N;i++){
            if(checker(row, i)){
                board[row][i] = true;
                nq_helper(row+1);
                board[row][i] = false;
            }
        }
    }
public:
    Solution(){
        vector<vector<bool>> b(9, vector<bool> (9, false));
        board = b;
    }
    int totalNQueens(int n){
        N = n;
        nq_helper(0);
        return ans.size();
    }
};