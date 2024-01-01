class Solution {
public:
    struct State{
        int id;
        int dis;
        State(int id, int dis) {
            this->id = id;
            this->dis = dis;
        }
        friend bool operator < (State a, State b) {
            return a.dis > b.dis;
        }
    };

    struct cmp {
        bool operator ()(State a, State b) {
            return a.dis > b.dis;
        }
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<State> > graph(n+1, vector<State>());
        for(auto edge: times) {
            int from = edge[0], to = edge[1], w = edge[2];
            graph[from].push_back(State(to, w));
        }
        vector<bool> vis(n+1, false);
        vector<int> dis(n+1, INT_MAX);
        priority_queue<State> pq;
        dis[k] = 0;
        pq.push(State(k, 0));
        while(!pq.empty()) {
            State cur = pq.top();
            pq.pop();
            int curId = cur.id;
            int curDis = cur.dis;
            if(vis[curId]) continue;
            vis[curId] = true;
            for(auto next: graph[curId]) {
                int nextId = next.id;
                int nextDis = next.dis + curDis;
                if(nextDis < dis[nextId]) {
                    dis[nextId] = nextDis;
                    pq.push(State(nextId, nextDis));
                }
            }
        }
        int res = 0;
        for(int i=1; i<=n; i++) {
            if(dis[i] == INT_MAX) {
                return -1;
            }
            res=max(res, dis[i]);
        }
        return res;
    }
};