class Solution {
public:
    vector<int> father,rank;
    int dis(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    int findfather(int x) {
        if(father[x] != x) {
            father[x] = findfather(father[x]);
        }
        return father[x];
    }

    bool Union(int x, int y) {
        int Fa = findfather(x);
        int Fb = findfather(y);
        if(Fa == Fb) {
            return false;
        }
        if(rank[Fa] > rank[Fb]) {
            swap(Fa, Fb);
        }
        rank[Fb] += rank[Fa];
        father[Fa] = Fb;
        return true;
    }

    struct Edge {
        int i, j, dis;
        Edge(int i, int j, int dis) {
            this->i = i;
            this->j = j;
            this->dis = dis;
        }
    };

    struct cmp {
        bool operator ()(Edge a, Edge b) {
            return a.dis < b.dis;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<Edge> edges;
        rank.resize(n, 1);
        father.resize(n);
        for(int i=0; i<n; i++) {
            father[i] = i;
        }
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int xi=points[i][0], yi=points[i][1];
                int xj=points[j][0], yj=points[j][1];
                edges.emplace_back(Edge(i, j, dis(xi, yi, xj, yj)));
            }
        }
        int res = 0;
        sort(edges.begin(), edges.end(), cmp());
        int count = 1;
        for(auto edge: edges) {
            if(count == n) {
                return res;
            }
            int from = edge.i, to = edge.j;
            int dis = edge.dis;
            if(!Union(from, to)) continue;
            res+=dis;
            count++;
        }
        return res;
    }
};