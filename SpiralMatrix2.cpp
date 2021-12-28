class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i = 0, j = 0;
        int p = 1;
        int dir = 0;
        vector<vector<int>>res(n, vector<int>(n, 0));
        while(p <= n*n){
            res[i][j] = p++;
            if(dir == 0){
                if((j + 1) < n and res[i][j+1] == 0){
                    j++;
                }
                else{
                    i++;
                    dir = 1;
                }
            }
            else if(dir == 1){
                if((i + 1) < n and res[i+1][j] == 0){
                    i++;
                }
                else{
                    dir = 2;
                    j--;
                }
            }
            else if(dir == 2){
                if((j -1) >=0 and res[i][j-1] == 0){
                    j--;
                }
                else{
                    dir = 3;
                    i--;
                }
            }
            else{
                if((i-1)>=0 and res[i-1][j] == 0){
                    i--;
                }
                else{
                    dir = 0;
                    j++;
                }
            }
        }
        return res;
    }
};
