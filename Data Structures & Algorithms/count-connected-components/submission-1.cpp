class Solution {
public:
    void dfs(int i, vector<vector<int>> & adj, vector<bool>& visited){
        visited[i]= true;
        for(int n : adj[i]){
            if(!visited[n]){
                dfs(n, adj, visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int count=0;
        vector<vector<int>> adj(n);
        //unordered_map<int, vector<int>> mp;
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  
        }
        vector<bool> visited (n, false);
        for(int i=0; i<n;i++){
            if(!visited[i]){
                count++;
            dfs(i, adj, visited);
            }
        }
        return count;

    }
};
