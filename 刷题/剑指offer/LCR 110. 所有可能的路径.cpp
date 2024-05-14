class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    void dfs(vector<vector<int>>& graph, int ind) {
        track.push_back(ind);
        int n = graph.size();
        if(ind == n - 1) {
            res.push_back(track);
            track.pop_back();
            return;
        }
        for(auto next : graph[ind]) {
            dfs(graph, next);
        }
        track.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return res;
    }
};