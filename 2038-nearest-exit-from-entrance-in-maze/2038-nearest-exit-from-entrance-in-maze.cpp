class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int steps = 0;
        maze[entrance[0]][entrance[1]] = '+';

        while (!q.empty()) {
            int sz = q.size();
            steps++;
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.') {
                        if (nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1) {
                            return steps;
                        }
                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};
