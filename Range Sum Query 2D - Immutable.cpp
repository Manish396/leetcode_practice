class NumMatrix {
public:
    vector<vector<int>>vip;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vip.resize(m, vector<int>(n, 0));
        vip[0][0] = matrix[0][0];
        for(int i = 1; i < n; i++){
            vip[0][i] = vip[0][i-1] + matrix[0][i];
        }
        for(int i = 1; i < m; i++){
            vip[i][0] = vip[i-1][0] + matrix[i][0];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                vip[i][j] = vip[i-1][j] + vip[i][j-1] - vip[i-1][j-1]+matrix[i][j];
                // cout << vip[i][j] <<" ";
            }
            // cout <<endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        sum += vip[row2][col2];
        if(col1 - 1 >=0){
            sum -= vip[row2][col1-1];
        }
        if(row1 - 1 >= 0){
            sum -= vip[row1-1][col2];
        }
        if(row1-1 >=0 and col1-1 >=0){
            sum += vip[row1-1][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
