//方法一：dijstra最短路
class Solution {
public:
    struct State {
        int id; //当前节点id
        int costFromSrc; // 当前节点到src节点花销
        int countFromSrc; // 当前节点到src节点经过的城市数
        friend bool operator <(const State& x, const State& y) {
            return x.costFromSrc > y.costFromSrc;
        } 
    };
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int> > > grid(n); //grid[from].first = to, grid[from].second = cost
        for(auto flight: flights) {
            int from = flight[0];
            int to = flight[1];
            int cost = flight[2];
            grid[from].push_back({to, cost});
        }
        vector<int> distTo(grid.size(), INT_MAX); //distTo[i]:i节点到src节点的最小花销 
        vector<int> countTo(grid.size(), INT_MAX); //countTo[i]:i节点到src节点经过的最小城市数
        priority_queue<State> qu;
        qu.push({src, 0, -1});
        while(!qu.empty()) {
            State cur = qu.top();
            int curId = cur.id;
            int curCost = cur.costFromSrc;
            int curCount = cur.countFromSrc;
            qu.pop();
            if(curId == dst) {
                return distTo[dst];
            }
            if(curCount == k) {
                continue;
            }
            for(int i=0; i<grid[curId].size(); i++) {
                auto nextNode = grid[curId][i];
                int nextId = nextNode.first;
                int toNextCost = nextNode.second + curCost;
                int toNextCount = curCount + 1;
                if(toNextCost < distTo[nextId]) {
                    distTo[nextId] = toNextCost;
                    countTo[nextId] = toNextCount;
                }
                if(toNextCost > distTo[nextId] && toNextCount > countTo[nextId]) continue;
                qu.push({nextId, toNextCost, toNextCount});
            }
        }
        return -1;
    }
};

// 方法二：动态规划
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int INF = 101*1e4+1;
        vector<vector<int> > dp(k+2, vector<int>(n, INF));
        dp[0][src] = 0;
        for(int t=1; t<=k + 1; t++) {
            for(auto& flight:flights) {
                int j = flight[0], i = flight[1], cost = flight[2];
                dp[t][i] = min(dp[t-1][j] + cost, dp[t][i]);
            }
        }
        int ans = INF;
        for(int t=1; t<=k+1; t++) {
            ans = min(ans, dp[t][dst]);
        }
        return ans == INF? -1:ans;
    }
};
