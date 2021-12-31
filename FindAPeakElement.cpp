class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int y = mat.size(), x = mat[0].size();
        int yend = y - 1, xend = x - 1, i = y>>1, j = x>>1;

        while(true){
          bool flag = true;
          if(i && mat[i-1][j] > mat[i][j])
              i--, flag = false;
          if(i != yend && mat[i+1][j] > mat[i][j])
              i++, flag = false;
          if(j         && mat[i][j-1] > mat[i][j]) 
              j--, flag = false;
          if(j != xend && mat[i][j+1] > mat[i][j]) 
              j++, flag = false;

          if(flag) return {i,j};
        }

        return {0,0};  
  }
};
