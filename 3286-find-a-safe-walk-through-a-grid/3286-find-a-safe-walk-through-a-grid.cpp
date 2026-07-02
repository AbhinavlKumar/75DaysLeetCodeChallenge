class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> min_cost(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;

        min_cost[0][0] = grid[0][0];
        dq.push_front({0, 0});

        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            if (x == m - 1 && y == n - 1) {
                break;
            }

            for (auto& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int new_cost = min_cost[x][y] + grid[nx][ny];
                    if (new_cost < min_cost[nx][ny]) {
                        min_cost[nx][ny] = new_cost;
                        if (grid[nx][ny] == 0) {
                            dq.push_front({nx, ny});
                        } else {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }

        return health - min_cost[m - 1][n - 1] >= 1;
    }
};