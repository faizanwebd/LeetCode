class Solution {
public:
    unordered_map<string, unordered_map<string, double>> g;

    double dfs(string u, string v, unordered_set<string>& vis) {
        if (!g.count(u) || !g.count(v)) return -1;
        if (u == v) return 1;
        vis.insert(u);
        for (auto& [nxt, val] : g[u])
            if (!vis.count(nxt)) {
                double res = dfs(nxt, v, vis);
                if (res != -1) return res * val;
            }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
        for (int i = 0; i < eq.size(); ++i) {
            g[eq[i][0]][eq[i][1]] = val[i];
            g[eq[i][1]][eq[i][0]] = 1 / val[i];
        }
        vector<double> res;
        for (auto& qr : q) {
            unordered_set<string> vis;
            res.push_back(dfs(qr[0], qr[1], vis));
        }
        return res;
    }
};
