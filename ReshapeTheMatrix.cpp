class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(r*c != m*n){
            return mat;
        }
        vector<vector<int>>mati(r, vector<int>(c, 0));
        int p = 0, q = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mati[p][q] = mat[i][j];
                q++;
                if(q == c) p++,q = 0;
            }
        }
        return mati;
    }
};
