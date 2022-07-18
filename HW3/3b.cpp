class Solution {
public:
    //BFS Helper Function
    bool bfs(vector<vector<char>> *grid, int i, int j) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        if ((*grid)[i][j] == '0') {
            return false;
        }
        (*grid)[i][j] = '0';
        queue<pair<int, int>> q({{i, j}});
        while (!q.empty()) {
            const auto [a, b] = q.front(); q.pop();
            for (const auto& d : directions) {
                const auto first = a + d.first;
                const auto second = b + d.second;
                if (!(0 <= first && first < grid->size() &&
                      0 <= second && second < (*grid)[0].size() &&
                      (*grid)[first][second] == '1')) {
                    continue;
                }
                (*grid)[first][second] = '0';
                q.emplace(first,second);
            }
        }
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (bfs(&grid, i, j)) {
                    ++count;
                }
            }
        }
        return count;
    }


};
