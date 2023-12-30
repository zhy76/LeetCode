class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>());
        vector<int> ingree(numCourses, 0);
        for(auto edge: prerequisites) {
            int from=edge[1], to=edge[0];
            ingree[to]++;
            graph[from].push_back(to);
        }
        queue<int> qu;
        for(int i=0; i<ingree.size(); i++){
            if(ingree[i] == 0) {
                qu.push(i);
            }
        }
        vector<int> ans;
        while(!qu.empty()){
            int sz=qu.size();
            for(int i=0; i<sz; i++) {
                int cur = qu.front();
                qu.pop();
                ans.push_back(cur);
                for(int next: graph[cur]) {
                    ingree[next]--;
                    if(ingree[next] == 0) {
                        qu.push(next);
                    }
                }
            }
        }
        if(ans.size() != numCourses) {
            return vector<int>{};
        }
        return ans;
    }
};