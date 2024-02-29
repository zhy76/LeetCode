class Solution {
public:
    bool ok = true;
    vector<bool> color;
    vector<bool> visited;
    void traverse(vector<vector<int> >& graph, int v) {
        if(!ok) {
            return;
        }
        visited[v] = true;
        for(auto next: graph[v]) {
            if(!visited[next]) {
                color[next] = !color[v];
                traverse(graph, next);
            } else {
                if(color[v] == color[next]) {
                    ok = false;
                    return;
                }
            }
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1, vector<int>());
        for(auto edge: dislikes) {
            int v1=edge[0], v2=edge[1];
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        color.resize(n+1);
        visited.resize(n+1);
        for(int i=1; i<=n; i++) {
            if(!ok) {
                return ok;
            }
            if(!visited[i]) {
                traverse(graph, i);
            }
        }
        return ok;
    }
};