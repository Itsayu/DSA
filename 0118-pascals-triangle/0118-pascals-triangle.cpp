class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle(numRows);

        pascalTriangle[0].push_back(1);

        for (int currentRow = 1; currentRow < numRows; currentRow++) {
            pascalTriangle[currentRow].push_back(1);

            vector<int>& currentRowList = pascalTriangle[currentRow];
            const vector<int>& previousRowList = pascalTriangle[currentRow - 1];

            for (int j = 1; j < previousRowList.size(); j++) {
                int sum = previousRowList[j] + previousRowList[j - 1];
                currentRowList.push_back(sum);
            }

            currentRowList.push_back(1);
        }

        return pascalTriangle;
    }
};