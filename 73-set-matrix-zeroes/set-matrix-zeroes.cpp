class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstrow = false;
        bool firstcol = false;

        // set first row and col to 0
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    if(i == 0) firstrow = true;
                    if(j == 0) firstcol = true;

                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // replace 0 
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    // set the [indx] 0
                    matrix[i][j] = 0;
                }
            }
        }

        // check the last elements in first row and col
        if(firstrow){
            for(int j = 0; j < n; j++){
                    matrix[0][j] = 0;
            }
        }

        if(firstcol){
            for(int i = 0; i < m; i++){
                    matrix[i][0] = 0;
            }
        }
    }
};