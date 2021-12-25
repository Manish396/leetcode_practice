class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int j = n - 1, i = 0;
        while(j >= 0 and i < m){
            if(j >= 0 and matrix[i][j] > target){
                j--;
                continue;
            }
            while(i < m and matrix[i][j] < target){
                i++;
            }
            if(i < m and j >=0  and matrix[i][j] == target){
                return true;
            }
        }
        return false;
    }
};
