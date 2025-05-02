class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int start, int k, int n, vector<int>& path) {
        if (path.size() == k) {
            if (n == 0) {
                result.push_back(path);
            }
            return;
        }

        for (int num = start; num <= 9; ++num) {
            if (num > n) break; 
            path.push_back(num);
            backtrack(num + 1, k, n - num, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        backtrack(1, k, n, path);
        return result;
    }
};
