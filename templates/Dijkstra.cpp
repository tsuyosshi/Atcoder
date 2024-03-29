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

template<typename T>
struct edge {
    int to;
    T cost;
    edge(int to, T cost) : to(to), cost(cost) {}
};

template<typename T>
void dijkstra(int s, T def, T init, vector<vector<edge<T>>> &G, vector<T> &dist, vector<int> &prev) {
    int n = G.size();
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    dist.assign(n, def);
    prev.assign(n, -1);
    dist[s] = init;
    pq.push(P(dist[s], s));
    while (pq.size()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (auto e: G[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                prev[e.to] = v;
                pq.emplace(dist[e.to], e.to);
            }
        }
    }
}

int N;

signed main() {
    cin >> N;
    vector<vector<edge<int>>> G(N+1);
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
    vector<int> dist(N+1);
    vector<int> prev(N+1);
    dijkstra<int>(0, INF, 0, G, dist, prev);
    int ans = INF;
    for (int i = 1; i <= N; ++i) cout << dist[i] << endl;
}