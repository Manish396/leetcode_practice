class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int s = 0;
        while(s < m){
            if(target > matrix[s][n-1]){
                s++;
            }
            else{
                break;
            }
        }
        if(s >= m){
            return false;
        }
        int e = 0;
        while(e <= n-1){
            if(matrix[s][e] == target){
                return true;
            }
            else{
                e++;
            }
        }
        return false;
    }
};
