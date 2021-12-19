class Solution {
public:
    /**
     * @param grid: the 2D grid
     * @return: the shortest distance
     */
    void BFS(const vector<vector<int>>& grid, int x, int y,
             vector<vector<int>> *dists, vector<vector<int>> *cnts) {
        int dist = 0, m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));

        vector<pair<int, int>> pre_level{{x, y}}, cur_level;
        visited[x][y] = true;
        while (!pre_level.empty()) {
            ++dist;
            cur_level.clear();
            for (const auto& p : pre_level) {
                int i, j;
                tie(i, j) = p;
                const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                        {-1, 0}, {1, 0}};
                for (const auto& d : directions) {
                    const int I = i + d.first, J = j + d.second;
                    if (0 <= I && I < m && 0 <= J && J < n &&
                        grid[I][J] == 0 && !visited[I][J]) {
                        (*dists)[I][J] += dist;
                        ++(*cnts)[I][J];
                        cur_level.push_back({I, J});
                        visited[I][J] = true;
                    }
                }
            }
            swap(pre_level, cur_level);
        }
    }
    int shortestDistance(vector<vector<int>> &grid) {
        // write your code here
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        vector<vector<int>> dists(m, vector<int>(n)), cnts(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++cnt;
                    BFS(grid, i, j, &dists, &cnts);
                }
            }
        }
        int shortest = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dists[i][j] < shortest && cnts[i][j] == cnt) {
                    shortest = dists[i][j];
                }
            }
        }

        return shortest != INT_MAX ? shortest : -1;
    }
};
