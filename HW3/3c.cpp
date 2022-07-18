class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        int gridSize = grid.size();
        //create a double ended queue, q
        deque<pair<int,int>> q;
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (grid[i][j] == 1) {
                    q.push_back({i, j});
                    break;
                }
            }
            if (!q.empty()){
                break;
            };
        }

        deque<pair<int, int>> points;
        set<pair<int, int>> visit;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        visit.insert(q.front());
        while (!q.empty()) {
            auto [a,b] = q.front();
            q.pop_front();
            for (int i = 0; i < 4; i++) {
                int x = a + dx[i];
                int y = b + dy[i];
                if (x >= 0 && x < gridSize && y >= 0 && y < gridSize) {
                    if (visit.count({x, y})) continue;
                    if (grid[x][y] == 0) points.push_back({x, y});
                    if (grid[x][y] == 1) q.push_back({x, y});
                    visit.insert({x, y});
                }
            }

        }

        int result = 1;
        int sz = points.size();
        while (sz > 0) {
            auto [a,b] = points.front();
            points.pop_front();
            sz--;
            for (int i = 0; i < 4; i++) {
                int x = a + dx[i];
                int y = b + dy[i];
                if (x >= 0 && x < gridSize && y >= 0 && y < gridSize) {
                    if (visit.count({x, y})) continue;
                    if (grid[x][y] == 0) points.push_back({x, y});
                    if (grid[x][y] == 1) return result;
                    visit.insert({x, y});
                }
            }
            if (sz == 0) {
                sz = points.size();
                result++;
            }
        }

        return result;
    }
};
