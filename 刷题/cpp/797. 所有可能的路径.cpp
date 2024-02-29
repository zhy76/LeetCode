class Solution {
public:
    vector<vector<int>> ans;
    void traverse(vector<vector<int>>& graph, int s, vector<int>& path){
        path.push_back(s);
        if(s == graph.size() - 1) {
            ans.push_back(path);
        }
        for(int i=0; i<graph[s].size(); i++) {
            traverse(graph, graph[s][i], path);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        traverse(graph, 0, path);
        return ans;
    }
};