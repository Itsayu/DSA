class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool box[9][9] = {}, hor[9][9] = {}, ver[9][9] = {};
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int mark = board[i][j]-'0'-1, k = ((int)i/3)*3+j/3;
                    if(box[k][mark] || hor[i][mark] || ver[j][mark])
                        return false;
                    box[k][mark] = hor[i][mark] = ver[j][mark] = true;
                }
            }
        }
        return true;
    }
};