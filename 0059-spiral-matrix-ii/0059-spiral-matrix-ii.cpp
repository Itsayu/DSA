class Solution {
public:
    vector<std::vector<int>> generateMatrix(int n) {
        vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

        int rowTop = 0;
        int rowBottom = matrix.size() - 1;
        int columnLeft = 0;
        int columnRight = matrix.size() - 1;

        int num = 1;
        while (true) {
            for (int i = columnLeft; i <= columnRight; i++) {
                matrix[rowTop][i] = num++;
            }
            rowTop++;

            if (rowTop > rowBottom || columnLeft > columnRight) {
                break;
            }
            for (int i = rowTop; i <= rowBottom; i++) {
                matrix[i][columnRight] = num++;
            }
            columnRight--;

            if (rowTop > rowBottom || columnLeft > columnRight) {
                break;
            }

            for (int i = columnRight; i >= columnLeft; i--) {
                matrix[rowBottom][i] = num++;
            }
            rowBottom--;

            if (rowTop > rowBottom || columnLeft > columnRight) {
                break;
            }

            for (int i = rowBottom; i >= rowTop; i--) {
                matrix[i][columnLeft] = num++;
            }
            columnLeft++;

            if (rowTop > rowBottom || columnLeft > columnRight) {
                break;
            }
        }
        return matrix;
    }
};