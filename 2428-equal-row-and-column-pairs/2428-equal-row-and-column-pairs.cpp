class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> rowMap;

        for (int i = 0; i < n; i++) {
            string key = "";
            for (int j = 0; j < n; j++) {
                key += to_string(grid[i][j]) + ",";
            }
            rowMap[key]++;
        }

        int count = 0;

        for (int j = 0; j < n; j++) {
            string key = "";
            for (int i = 0; i < n; i++) {
                key += to_string(grid[i][j]) + ",";
            }
            if (rowMap.find(key) != rowMap.end()) {
                count += rowMap[key];
            }
        }

        return count;
    }
};
