class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> ingree(numCourses, 0);
        vector<vector<int> > graph(numCourses, vector<int>());
        for(auto prerequisite : prerequisites) {
            int from = prerequisite[1];
            int to = prerequisite[0];
            graph[from].push_back(to);
            ingree[to]++;
        }
        queue<int> qu;
        for(int i = 0; i < numCourses; i++) {
            if(ingree[i] == 0) {
                qu.push(i);
            }
        }
        while(!qu.empty()) {
            int sz = qu.size();
            for(int i = 0; i < sz; i++) {
                int cur = qu.front();
                qu.pop();
                res.push_back(cur);
                for(auto next : graph[cur]) {
                    ingree[next]--;
                    if(ingree[next] == 0) {
                        qu.push(next);
                    }
                }
            }
        }
        if(res.size() != numCourses) return vector<int>{};
        return res;
    }
};