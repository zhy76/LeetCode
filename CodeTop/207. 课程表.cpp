class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ingree(numCourses, 0);
        vector<vector<int> > grid(numCourses, vector<int>());
        for(auto prerequisite: prerequisites) {
            int x = prerequisite[0];
            int y = prerequisite[1];
            ingree[y]++;
            grid[x].push_back(y);
        }
        queue<int> qu;
        int inqueue = 0;
        for(int i = 0; i < numCourses; i++) {
            if(ingree[i] == 0) {
                qu.push(i);
                inqueue++;
            }
        }
        while(!qu.empty()) {
            int sz = qu.size();
            for(int i = 0; i < sz; i++) {
                int cur = qu.front();
                qu.pop();
                for(auto next : grid[cur]) {
                    ingree[next]--;
                    if(ingree[next] == 0) {
                        qu.push(next);
                        inqueue++;
                    }
                }
            }
        }
        return inqueue == numCourses;
    }
};