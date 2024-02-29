class Solution {
public:
    struct State {
        int id;
        double probe;
        State(int id, double probe) {
            this->id = id;
            this->probe = probe;
        }
        friend bool operator < (State x, State y) {
            return x.probe < y.probe;
        }
    };

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<State> > graph(n, vector<State>());
        for(int i=0; i<edges.size(); i++) {
            int from = edges[i][0], to = edges[i][1];
            double probe = succProb[i];
            graph[from].push_back({to, probe});
            graph[to].push_back({from, probe});
        }
        vector<double> max_probe(n, -1);
        vector<bool> vis(n, false);
        priority_queue<State> qu;
        qu.push({start_node, 1});
        while(!qu.empty()) {
            State cur = qu.top();
            qu.pop();
            int cur_id = cur.id;
            double cur_probe = cur.probe;
            if(cur_id == end_node) {
                return cur_probe;
            }
            if(vis[cur_id]) continue;
            vis[cur_id] = true;
            for(auto next: graph[cur_id]) {
                int next_id = next.id;
                double next_probe = next.probe * cur_probe;
                if(next_probe > max_probe[next_id]) {
                    max_probe[next_id] = next_probe;
                    qu.push({next_id,next_probe});
                }
            }
        }
        return 0.0;
    }
};