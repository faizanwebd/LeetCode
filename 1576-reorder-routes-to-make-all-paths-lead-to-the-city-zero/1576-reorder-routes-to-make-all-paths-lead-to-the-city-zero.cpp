class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        vector<bool> visited(n, false);
        
        for (auto& conn : connections) {
            graph[conn[0]].emplace_back(conn[1], 1);
            graph[conn[1]].emplace_back(conn[0], 0);
        }
        
        int changes = 0;
        
        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (auto& [neighbor, direction] : graph[node]) {
                if (!visited[neighbor]) {
                    changes += direction;
                    dfs(neighbor);
                }
            }
        };
        
        dfs(0);
        return changes;
    }
};
