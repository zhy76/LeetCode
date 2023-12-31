class Solution {
public:
    struct State{
        int id;
        int dis;
        State(int id, int dis) {
            this->id = id;
            this->dis = dis;
        }
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int> > > graph(n+1, vector<pair<int,int>>());
        for(auto edge: times) {
            int from=edge[0], to=edge[1], w=edge[2];
            graph[from].push_back({to, w});
        }
        vector<bool> vis(n+1, false);
        vector<int> dis(n+1, INT_MAX);
        priority_queue<State, vector<State>, function<bool(State, State)>> pq([](State a, State b){
            return a.dis > b.dis;
        });
        dis[k] = 0;
        pq.push(State(k, 0));
        while(!pq.empty()) {
            State cur = pq.top();
            int curId = cur.id;
            int curDis = cur.dis;
            pq.pop();
            if(vis[curId]) {
                continue;
            }
            vis[curId] = true;
            for(auto next: graph[curId]) {
                if(next.second + curDis < dis[next.first]) {
                    dis[next.first] = next.second + curDis;
                    pq.push(State(next.first, dis[next.first]));
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(dis[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, dis[i]);
        }
        return ans;
    }
};