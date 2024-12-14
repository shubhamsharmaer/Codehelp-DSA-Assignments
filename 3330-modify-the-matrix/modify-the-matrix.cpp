class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();  // rows
        int n = matrix[0].size(); // colums

        // unordered map
        vector<int> maxNumber(n, 0);

        // find max value
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] > maxNumber[j]){
                    maxNumber[j] = matrix[i][j];
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] < 0){
                    matrix[i][j] = maxNumber[j];
                }
            }
        }
        return matrix;
    }
};