class Solution {
public:
    int dp[101][101] = {0};
    int minSum(vector<vector<int>>& matrix, int i, int j){
        if(i == matrix.size()){
            return 0;
        }
        if(dp[i][j]!= 0) return dp[i][j];
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        a = minSum(matrix, i+1, j);
        if(j-1 >= 0)
            b = minSum(matrix, i+1, j - 1);
        if(j + 1 < matrix.size())
            c = minSum(matrix, i+1, j + 1);
        return dp[i][j] = min(a, min(b, c)) + matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, minSum(matrix, 0, i));
        }
        return ans;
    }
};
