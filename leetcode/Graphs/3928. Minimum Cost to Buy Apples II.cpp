class Solution {
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) 
    {
        vector<vector<pair<int,long long>>> emptyG(n), loadedG(n);

    for (auto &e : roads) {
        int u = e[0], v = e[1];
        long long cost = e[2], tax = e[3];

        emptyG[u].push_back({v, cost});
        emptyG[v].push_back({u, cost});

        loadedG[u].push_back({v, cost * tax});
        loadedG[v].push_back({u, cost * tax});
    }

    auto dijkstra = [&](int src,
                        vector<vector<pair<int,long long>>> &g) {

        vector<long long> dist(n, 1e18);
        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d,u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &[v,w] : g[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    };

    vector<long long> ans(n, 1e18);

    for (int shop = 0; shop < n; shop++) {

        auto emptyDist = dijkstra(shop, emptyG);
        auto loadedDist = dijkstra(shop, loadedG);

        for (int i = 0; i < n; i++) {

            ans[i] = min(
                ans[i],
                emptyDist[i] + prices[shop] + loadedDist[i]
            );
        }
    }

    vector<int> res(n);

    for (int i = 0; i < n; i++)
        res[i] = (int)ans[i];

    return res;
    }
};