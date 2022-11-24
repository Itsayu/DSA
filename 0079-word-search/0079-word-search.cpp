class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int i, int j, int k) {
        if(k == word.length())
            return true;
        if(i >= board.size() || i < 0 || j < 0 || j >= board[0].size() || board[i][j] != word[k])
            return false;
        bool res = false;

        board[i][j] = '-';
        res = helper(board, word, i+1, j, k+1) || helper(board, word, i-1, j, k+1) || helper(board, word, i, j+1, k+1) || helper(board, word, i, j-1, k+1);
        board[i][j] = word[k];
        
        return res;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(helper(board, word, i, j, 0))
                    return true;
            }
        }
        return false;    
    }
};