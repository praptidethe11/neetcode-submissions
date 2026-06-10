class Solution {
public:
    void connected(int i,
                   unordered_map<int, vector<int>>& nodes,
                   vector<bool>& visited) {

        visited[i] = true;

        for (int f : nodes[i]) {
            if (!visited[f]) {
                connected(f, nodes, visited);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() != n - 1)
            return false;

        unordered_map<int, vector<int>> nodes;

        for (auto &e : edges) {
            nodes[e[0]].push_back(e[1]);
            nodes[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        connected(0, nodes, visited);

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }

        return true;
    }
};