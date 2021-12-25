class Solution {
public:
    bool isValid(int x, int y, int m, int n){
        if(x >= 0 && x <= m-1 && y >= 0 && y <= n-1)
            return true;
        return false;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int color = image[sr][sc];
        image[sr][sc] = newColor;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; ++i){
                if(isValid(x + dx[i], y + dy[i], m, n) && image[x + dx[i]][y + dy[i]] == color && image[x + dx[i]][y + dy[i]] != newColor) {
                    image[x + dx[i]][y + dy[i]] = image[x][y];
                    q.push({x + dx[i], y + dy[i]});
                }
            }
        }
        return image;
    }
};
