typedef long long int ll;
#define pii pair<ll,ll>
#define F first
#define S second

const ll INF = 1e18;

vector<vector<ll>> path (26);
vector<vector<pii>> g (26);

void Dijkstra (int src) {
    vector<ll> cost(26, INF);
    cost[src] = 0;
    
    set<pii> all;
    for (int j = 0; j < 26; j ++) all.insert({cost[j], j});
    
    while (!all.empty()) {
        int cur = all.begin() -> S;
        all.erase(all.begin());
        
        for (auto [child, w]: g[cur]) {
            if (cost[child] <= (cost[cur] + w)) continue;
            
            all.erase({cost[child], child});
            cost[child] = cost[cur] + w;
            all.insert({cost[child], child});
        }
    }
    
    path[src] = cost;
}
