class Solution {
public:
    vector<bool> color;
    vector<bool> visited;
    bool ok = true;
    void traverse(vector<vector<int>>& graph,int s) {
        if(!ok) {
            return;
        }
        visited[s] = true;
        for(auto next: graph[s]) {
            if(!visited[next]) {
                color[next] = !color[s];
                traverse(graph, next);
            } else {
                if(color[s] == color[next]) {
                    ok = false;
                    return;
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.resize(n);
        visited.resize(n);
        for(int i=0; i<n; i++) {
            if(!ok) break;
            if(!visited[i]){
                traverse(graph, i);
            }
        }
        return ok;
    }
};