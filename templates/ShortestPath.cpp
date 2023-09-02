#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

typedef pair<int, int> PI;
typedef pair<int, pair<int, int>> PII;
static const int INF = 1010000000000000017LL;
static const double eps = 1e-12;
static const double pi = 3.14159265358979323846;
static const int dx[4] = {1, -1, 0, 0};
static const int dy[4] = {0, 0, 1, -1};
static const int ddx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
static const int ddy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

template<class T> inline bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }

vector<int> bfs(int s, vector<vector<int>> &G){
    int n = G.size();
    queue<int> que;
    vector<int> dist(n, INF);
    que.push(s);
    dist[s] = 0;
    while (que.size() > 0) {
        int v = que.front();
        que.pop();
        for (auto u: G[v]) {
            if (dist[u] != INF) continue;
            que.push(u);
            dist[u] = dist[v] + 1;
        }  
    }
    return dist;
}

vector<int> dijkstra(int s, vector<vector<PI>> &G) {
    int n = G.size();
    priority_queue<PI, vector<PI>, greater<PI>> pq;
    vector<int> dist(n, INF);
    dist[s] = 0;
    pq.emplace(dist[s], s);
    while (pq.size() > 0) {
        auto p = pq.top();
        pq.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (auto e: G[v]) {
            int u = e.first, cost = e.second;
            if (dist[u] > dist[v] + cost) {
                dist[u] = dist[v] + cost;
                pq.emplace(dist[u], u);
            }
        }
    }
    return dist;
}

int N;

signed main() {
    cin >> N;
    vector<vector<PI>> G(N+1);
    for (int i = 1; i <= N; ++i) {
        int s;
        cin >> s;
        if (i != N) {
            G[i].emplace_back(i+1, s);
        } else {
            G[i].emplace_back(1, s);
        }
    }
    for (int i = 1; i <= N; ++i) {
        int t;
        cin >> t;
        G[0].emplace_back(i, t);
    }
    auto dist = dijkstra(0, G);
    int ans = INF;
    for (int i = 1; i <= N; ++i) cout << dist[i] << endl;
}