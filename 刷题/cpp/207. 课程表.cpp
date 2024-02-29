class Solution {
public:
    vector<bool> onPath;
    vector<bool> visited;
    bool hasCycle = false;
    void traverse(vector<vector<int> >& graph, int s){
        if(onPath[s]) {
            hasCycle = true;
        }
        if(visited[s] || hasCycle) {
            return;
        }
        visited[s] = true;
        onPath[s] = true;
        for(int i=0; i<graph[s].size(); i++) {
            traverse(graph, graph[s][i]);
        }
        onPath[s] = false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses,vector<int>());
        for(auto edge: prerequisites) {
            int from = edge[0], to = edge[1];
            graph[from].push_back(to);
        }
        visited = vector<bool>(numCourses, false);
        onPath = vector<bool>(numCourses, false);
        for(int i=0; i<numCourses; i++) {
            traverse(graph, i);
        }
        return !hasCycle;
    }
};