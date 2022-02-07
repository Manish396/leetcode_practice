class Solution {
public:
    void collumn(vector<vector<int>>& matrix, int j){
        int m = matrix.size();
        for(int i = 0; i < m; i++){
            matrix[i][j] = 0;
        }
    }
    void row(vector<vector<int>>& matrix, int i){
        int n = matrix[0].size();
        for(int j = 0; j < n; j++){
            matrix[i][j] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool fl1 = false, fl2 = false;
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 0){
                fl1 = true;
            }
        }
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                fl2 = true;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n;j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < n; i++){
            if(matrix[0][i] == 0){
                collumn(matrix, i);
            }
        }
        for(int j = 1; j < m; j++){
            if(matrix[j][0] == 0){
                row(matrix, j);
            }
        }
        if(matrix[0][0] == 0){
            collumn(matrix, 0);
            row(matrix, 0);
        }
        if(fl1){
            row(matrix, 0);
        }
        if(fl2){
            collumn(matrix, 0);
        }
    }
};
