class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> vec(m, vector<int>(n, 0));
        if (m*n != original.size()) return vector<vector<int>>();
        int index = 0;
        for(int i = 0; i < original.size(); i++){
            // for(int j = 0; j < n; j++){
            //     vec[i][j] = original[index];
            //     index++;
            // }
            vec[i/n][i%n] = original[i];
        }
        return vec;
    }
};